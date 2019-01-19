#!/bin/bash

PORTSTART=3010
trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

echo "WARNING: This program attaches intentionally vulnerable programs"
echo "to sockets, making them accessible to other computers with access"
echo "to your network"
cd ..

declare -A programs
for i in $(find /app/src/ | sort); do
	FNAME=$(basename -- "${i%.*}")
	if [[ "$FNAME" =~ "level" ]]; then
		PORT=$PORTSTART
		let "PORTSTART=PORTSTART+1"
	else
		continue
	fi
	printf "Attaching %s to port %i\n" $FNAME $PORT
	socat TCP-LISTEN:$PORT.reuseaddr,fork EXEC:./bin/$FNAME & 
	programs+=(["$PORT"]="$FNAME")
	PIDS+=($!)
done

echo "" > /app/log.html
echo "<html><div><code>" >> /app/log.html

THEGAME=$(grep Game /app/README.md -A 16 | cut -d \| -f 2,3)
echo "${THEGAME//$'\n'/<br />}" >> /app/log.html
echo "</div><br /><br />" >> /app/log.html

echo "port program<br />" >> /app/log.html

for port in "${!programs[@]}"; do
	printf '%s:%s<br />\n' "$port" "${programs[$port]}"
done | sort >> /app/log.html

if [ -d "/app/www" ]; then
        echo "<br /><b>Binaries can be found in /bin, source in /src.</b><br />" >> /app/log.html
        echo "</code></div></html>" >> /app/log.html
	mv /app/log.html /app/www/README.html
else
	echo "</code></div></html>" >> /app/log.html
fi

printf "Processes connected!\n"
while read -p "Press 'q' to quit, any other key to continue: " word; do
	if [[ "$word" == 'q' ]]; then
		echo "Terminating child processes..."
		break
	fi
done
