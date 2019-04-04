FROM i386/ubuntu:19.04 
WORKDIR /app 
COPY src/* /app/src/    
COPY Makefile /app/
COPY scripts/*.sh /app/scripts/

RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ gcc libc6-dev socat lighttpd make && rm -rf /var/lib/apt/lists/* \
    && make && useradd flag -M && chown flag:flag -R /app/bin \
    && chmod 4755 -R /app/bin && ln -s /var/www/html /app/www \ 
    && ln -s /app/bin /app/www/bin && ln -s /app/src /app/www/src \
    && cp /lib/i386-linux-gnu/libc.so.6 /app/bin \
    && apt-get remove g++ gcc -y && rm -rf /var/lib/apt/lists/* \
    && echo 'dir-listing.activate = "enable"' >> /etc/lighttpd/lighttpd.conf 

COPY README.md /app/README.md
RUN chmod +x /app/scripts/runDocker.sh

ENTRYPOINT ["/app/scripts/runDocker.sh"]
