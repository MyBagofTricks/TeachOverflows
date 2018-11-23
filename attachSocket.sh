#!/bin/bash

ROPSTART=3030
STACKSTART=3010
trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

echo "WARNING: This program attaches intentionally vulnerable programs"
echo "to sockets, making them accessible to other computers with access"
echo "to your network"

for i in $(find overflows/ | sort); do
	FNAME=$(basename -- "$i")
	if [[ "$FNAME" =~ "stack" ]]; then
		PORT=$STACKSTART
		let "STACKSTART=STACKSTART+1"
	elif [[ $FNAME  =~ "rop" ]]; then
		PORT=$ROPSTART
		let "ROPSTART=ROPSTART+1"
	else
		continue
	fi
	printf "Attaching %s to port %i\n" $FNAME $PORT
	socat TCP-LISTEN:$PORT.reuseaddr,fork EXEC:./overflows/$FNAME & 
	PIDS+=($!)
done
printf "Processes connected!\n"

while read -p "Press 'q' to quit, any other key to continue: " word; do
	if [[ "$word" == 'q' ]]; then
		echo "Terminating child processes..."
		break
	fi
done
