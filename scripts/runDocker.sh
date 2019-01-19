#!/bin/bash

md5sum <<< "secret flag is only readable y flag" | awk '{print $1}' > /app/bin/secretflag.txt
chmod 600 /app/bin/secretflag.txt 
chown flag:flag /app/bin/secretflag.txt 
lighttpd -f /etc/lighttpd/lighttpd.conf

#/bin/bash
/app/scripts/attachSocket.sh


