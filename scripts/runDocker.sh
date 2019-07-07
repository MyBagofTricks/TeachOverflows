#!/bin/bash
# default user:pass is overflow:overflow  
# To change the password, use:
#     mkpasswd -m sha-512 <yourpassword> 
# then replace the following hash:
HASH='$6$NEL4AIb6d$buPNGywP9FNpNMTWhIn8jBBaHNmEkzFCej.lxkH0Ml9lwc2JdN1O.JR1jPW6IGSb8ObDhCGigbE0v7NtpbJzh0'
# To skip passwords completely, ensure an appropriate authorized_keys is in
# the scripts/ directory before building the container

#useradd -s /bin/bash -m overflow
useradd -s /bin/bash -m overflow
if [ -f /app/scripts/authorized_keys ]; then
	mkdir -p /home/overflow/.ssh
	cp /app/scripts/authorized_keys /home/overflow/.ssh
	chown root:overflow /home/overflow/.ssh/authorized_keys
	chmod 640 /home/overflow/.ssh/authorized_keys
	echo 'PasswordAuthentication no' >> /etc/ssh/sshd_config
else
	usermod -p "${HASH}" overflow
fi

useradd flag -M && chown flag:flag -R /app/bin
chmod 4755 -R /app/bin 
ln -s /var/www/html /app/www
ln -s /app/bin /app/www/bin && ln -s /app/src /app/www/src
ln -s /app/bin /home/overflow/challenges

md5sum <<< "secret flag is only readable by flag" | awk '{print $1}' > /app/bin/secretflag.txt
chmod 440 /app/bin/secretflag.txt 
chown root:flag /app/bin/secretflag.txt 
lighttpd -f /etc/lighttpd/lighttpd.conf

sed -i 's/int SECRET\[.*$/int SECRET\[32\] \= \{0x49,0x48,0x19,0x15,0x10,0x11,0x15,0x47,0x14,0x13,0x16,0x4c,0x4b,0x19,0x17,0x16,0x4b,0x48,0x13,0x18,0x4b,0x14,0x15,0x14,0x15,0x15,0x13,0x17,0x12,0x10,0x13,0x12\}\;/' /app/src/*

service ssh start
/bin/bash
