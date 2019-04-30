#!/usr/bin/env bash

PORTSTART=3001
trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

declare -A programs
for i in $(find /app/bin/ | sort); do
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
	cat > /app/www/index.html << __EOF__
<html><body><div><pre>$THEGAME
<br /><b>Binaries are in <a href="bin/">bin/</a>
<br />Source in <a href="src/">src/</a></b>
<br />ASLR enabled. Libc was recently loaded to $LEAKER"
</pre></div></body></html>
__EOF__
fi

printf "Processes connected!\n"
echo  "$THEGAME"
echo "WARNING: This program attaches intentionally vulnerable programs"
echo "to sockets, making them accessible to other computers with access"
echo "to your network"

while read -p "Press 'q' to quit, any other key to continue: " word; do
	if [[ "$word" == 'q' ]]; then
		echo "Terminating child processes..."
		break
	fi
done
