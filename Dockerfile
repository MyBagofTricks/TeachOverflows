FROM i386/ubuntu:18.04 
WORKDIR /app 

RUN apt-get update && apt install -y --no-install-recommends \
    gcc libc6-dev lighttpd make openssh-server python3 

# revert to one cmd with copy above when done testing
COPY . /app/
RUN rm -rf /var/lib/apt/lists/* && make \
    && apt-get remove gcc -y && rm -rf /var/lib/apt/lists/* \
    && apt-get autoremove -y \
    && echo 'dir-listing.activate = "enable"' >> /etc/lighttpd/lighttpd.conf \
    && rm -f /app/Dockerfile /app/Makefile /app/_config.yml /app/src/magic.c \
    && rm -rf /app/docs /app/scripts/encoder.py /app/scripts/flags.txt \
    && chmod +x /app/scripts/runDocker.sh

ENTRYPOINT ["/app/scripts/runDocker.sh"]
