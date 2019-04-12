#!/bin/bash

md5sum <<< "secret flag is only readable by flag" | awk '{print $1}' > /app/bin/secretflag.txt
chmod 600 /app/bin/secretflag.txt 
chown flag:flag /app/bin/secretflag.txt 
rm /app/src/magic.c
lighttpd -f /etc/lighttpd/lighttpd.conf

#/bin/bash
/app/scripts/attachSocket.sh

