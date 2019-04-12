#!/usr/bin/env bash

PORTSTART=3001
trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

echo "WARNING: This program attaches intentionally vulnerable programs"
echo "to sockets, making them accessible to other computers with access"
echo "to your network"
#cd ..

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
	socat TCP-LISTEN:$PORT.reuseaddr,fork EXEC:/app/bin/$FNAME & 
	programs+=(["$PORT"]="$FNAME")
	PIDS+=($!)
done

THEGAME=$(grep Game /app/README.md -A 16 | cut -d \| -f 2,4)
LEAKER=$(ldd /app/bin/level01 | grep libc | awk '{print $4}')

if [ -d "/app/www" ]; then
	echo "<html><div><code>" > /app/www/index.html
	echo "${THEGAME//$'\n'/<br />}" >> /app/www/index.html
	echo "$programs <br />" >> /app/www/index.html
        echo "<br /><b>Binaries can be found in /bin, source in /src.</b><br />" >> /app/www/index.html
        echo "ASLR is enabled. Libc was recently loaded to ${LEAKER//$'\n'/<br />}" >> /app/www/index.html
	echo "</code></div></html>" >> /app/www/index.html
fi

printf "Processes connected!\n"
while read -p "Press 'q' to quit, any other key to continue: " word; do
	if [[ "$word" == 'q' ]]; then
		echo "Terminating child processes..."
		break
	fi
done
