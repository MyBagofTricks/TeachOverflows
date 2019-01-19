#!/bin/sh

set -e

adduser -D flag flag
chmod 755 -R /app/bin
chown flag:flag -R /app/bin
chmod +s -R /app/bin
chmod +x /app/run.sh

cat > /app/bin/secretflag.txt << 'EOF'
this is only readable by u:flag!
EOF

chmod 600 /app/bin/secretflag.txt
chown flag:flag /app/bin/secretflag.txt

