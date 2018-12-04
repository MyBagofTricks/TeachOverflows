#!/bin/sh
DEST=$PWD

if !(which gcc > /dev/null); then
    echo "Error: gcc not detected."
    exit
fi

mkdir -p ${DEST}/bin
# Build level 0. No special requirements
for i in $(find -name "*0?.c"); do	
	fname=$(basename -- "$i")
	fname="${fname%.*}"
	gcc "$i" -o ${DEST}/bin/${fname} -m32
done

# Build level 1. Stack protections disabled
for i in $(find -name "*1?.c"); do
	fname=$(basename -- "$i")
	fname="${fname%.*}"
	gcc "$i" -o ${DEST}/bin/${fname} -fno-stack-protector -no-pie -m32 -Wall -Wformat=0
done


printf "Build complete!\n"
printf "Disregard any warnings, they're just a product of my bad c :)\n"
printf "Remember, these programs can be wrapped to a socket:\n"
printf "\tusing netcat: $ ncat -e ./stack1 -lkvnp 9000\n"
printf "\tusing socat:  $ socat TCP-LISTEN:9000.reuseaddr,fork EXEC:./stack01\n"
printf "Attackers connect with netcat:\n"
printf "\tplain connect: ncat <ip address> 9000\n"
printf "\tpipe perl out: perl -e 'print \"A\"*1337 .\"HAX\" | ncat <ip address> 9000\n"
