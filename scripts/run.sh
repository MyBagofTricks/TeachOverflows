#!/bin/bash

ln -s /var/www/localhost/htdocs /app/www
cp /lib/ld-musl-i386.so.1 /app/bin
ln -s /app/bin /app/www/bin && ln -s /app/src /app/www/src
lighttpd -f /etc/lighttpd/lighttpd.conf
#/bin/bash
/app/scripts/attachSocket.sh
