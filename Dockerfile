FROM i386/alpine:3.8
WORKDIR /app 

RUN apk add --update --no-cache bash socat build-base lighttpd && \
    wget -qO- https://github.com/MyBagofTricks/TeachOverflows/tarball/master \
    | tar -xzC /app --strip-component=1 && make \
    && sed -i '/dir\-listing\.activate/s/^#//g' /etc/lighttpd/lighttpd.conf \
    && apk update && apk del build-base && rm /app/src/magic.c \
    && adduser -D flag flag && chown flag:flag -R /app/bin \
    && chmod 4755 -R /app/bin && chmod +x /app/scripts/run.sh \
    && ln -s /var/www/localhost/htdocs /app/www \
    && ln -s /app/bin /app/www/bin && ln -s /app/src /app/www/src \
    && cp /lib/ld-musl-i386.so.1 /app/bin 
    
COPY scripts/* /app/scripts/

RUN chmod +x /app/scripts/runDocker.sh

ENTRYPOINT ["/app/scripts/runDocker.sh"]
