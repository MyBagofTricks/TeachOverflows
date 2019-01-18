#!/bin/sh
DEST=$PWD

if !(which gcc > /dev/null); then
    echo "Error: gcc not detected."
    exit
fi

mkdir -p ${DEST}/bin
for i in $(find src/ -regex '.*[0-9]\.c'); do
	fname=$(basename -- "$i")
	fname="${fname%.*}"
	gcc "$i" -o ${DEST}/bin/${fname} -fno-stack-protector -no-pie -m32 -Wall -Wformat=0
done


printf "[^] Build complete!\n"
printf "[ ] Remember, these programs can be wrapped in a socket\n"
printf "[!] netcat: $ ncat -e ./stack1 -lkvnp 9000\n"
printf "[!] socat:  $ socat TCP-LISTEN:9000.reuseaddr,fork EXEC:./stack01\n"
printf "[ ] Attackers connect with netcat:\n"
printf "[ ] plain connect: ncat <ip address> 9000\n"
printf "[ ] pipe perl out: perl -e 'print \"A\"*1337 .\"HAX\" | ncat <ip address> 9000\n"
