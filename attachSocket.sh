#!/bin/bash

OTHERSTART=3020
STACKSTART=3010
trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

echo "WARNING: This program attaches intentionally vulnerable programs"
echo "to sockets, making them accessible to other computers with access"
echo "to your network"

declare -A programs
for i in $(find src/ | sort); do
	FNAME=$(basename -- "${i%.*}")
	if [[ "$FNAME" =~ "stack" ]]; then
		PORT=$STACKSTART
		let "STACKSTART=STACKSTART+1"
	elif [[ $FNAME  =~ "rop" ||  $FNAME  =~ "format" || $FNAME  =~ "heap"  ]]; then
		PORT=$OTHERSTART
		let "OTHERSTART=OTHERSTART+1"
	else
		continue
	fi
	printf "Attaching %s to port %i\n" $FNAME $PORT
	socat TCP-LISTEN:$PORT.reuseaddr,fork EXEC:./bin/$FNAME & 
	programs+=(["$PORT"]="$FNAME")
	PIDS+=($!)
done

echo "" > log.html
echo "<html><div><code>" >> log.html

THEGAME=$(grep Game README.md -A 16 | cut -d \| -f 2,3)
echo "${THEGAME//$'\n'/<br />}" >> log.html
echo "</div><br /><br />" >> log.html

echo "port program<br />" >> log.html

for port in "${!programs[@]}"; do
	printf '%s:%s<br />\n' "$port" "${programs[$port]}"
done | sort >> log.html

if [ -d "www" ]; then
        echo "<br /><b>Binaries can be found in /bin.</b><br />" >> log.html
        echo "</code></div></html>" >> log.html
	mv /app/log.html /app/www/README.html
else
	echo "</code></div></html>" >> log.html
fi

printf "Processes connected!\n"
while read -p "Press 'q' to quit, any other key to continue: " word; do
	if [[ "$word" == 'q' ]]; then
		echo "Terminating child processes..."
		break
	fi
done
