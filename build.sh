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
	gcc "$i" -o ${DEST}/bin/${fname} -fno-stack-protector -no-pie -m32
done


echo "Build complete!\n"	
echo "Remember, these programs can be wrapped to a socket:"
echo "  using netcat: $ ncat -e ./stack1 -lkvnp 9000"
echo "  using socat:  $ socat TCP-LISTEN:9000.reuseaddr,fork EXEC:./stack01"
echo "Attackers connect with netcat:"
echo "  plain connect: ncat <ip address> 9000"
echo """  pipe perl out: perl -e 'print "A"*1337 . "HAX\n" | ncat <ip address> 9000"""
