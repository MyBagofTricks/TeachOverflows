#!/bin/bash

ROPSTART=3050
STACKSTART=3010
FORMATSTART=3030
trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

echo "WARNING: This program attaches intentionally vulnerable programs"
echo "to sockets, making them accessible to other computers with access"
echo "to your network"
echo "" > log

for i in $(find bin/ | sort); do
	FNAME=$(basename -- "$i")
	if [[ "$FNAME" =~ "stack" ]]; then
		PORT=$STACKSTART
		let "STACKSTART=STACKSTART+1"
	elif [[ $FNAME  =~ "rop" ]]; then
		PORT=$ROPSTART
		let "ROPSTART=ROPSTART+1"
	elif [[ $FNAME  =~ "format" ]]; then
		PORT=$FORMATSTART
		let "FORMATSTART=FORMATSTART+1"
	else
		continue
	fi
	printf "Attaching %s to port %i\n" $FNAME $PORT
	echo "${FNAME}:${PORT}" >> log
	socat TCP-LISTEN:$PORT.reuseaddr,fork EXEC:./bin/$FNAME & 
	PIDS+=($!)
done
printf "Processes connected!\n"

while read -p "Press 'q' to quit, any other key to continue: " word; do
	if [[ "$word" == 'q' ]]; then
		echo "Terminating child processes..."
		break
	fi
done
