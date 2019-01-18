#!/bin/bash

OTHERSTART=3020
STACKSTART=3010
trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

echo "WARNING: This program attaches intentionally vulnerable programs"
echo "to sockets, making them accessible to other computers with access"
echo "to your network"
echo "<html>" > log.html

echo "<div><table><tr><th>Program</th><th>Port</th></tr>" >> log.html
for i in $(find src/ | sort); do
	FNAME=$(basename -- "$i")
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
	echo "<tr><th>${FNAME}</th><th>${PORT}</th></tr>" >> log.html
	socat TCP-LISTEN:$PORT.reuseaddr,fork EXEC:./bin/$FNAME & 
	PIDS+=($!)
done
echo "</tr></table></div>" >> log.html

echo "<div>" >> log.html
while read LINE; do
	echo "<p>${LINE}</p>" >> log.html
done < README.md
echo "</div>" >> log.html

echo "</html>" >> log.html
printf "Processes connected!\n"

while read -p "Press 'q' to quit, any other key to continue: " word; do
	if [[ "$word" == 'q' ]]; then
		echo "Terminating child processes..."
		break
	fi
done
