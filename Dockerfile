FROM i386/alpine:3.8
WORKDIR /app 

RUN apk add --update --no-cache bash socat build-base lighttpd && \
    wget -qO- https://github.com/MyBagofTricks/TeachOverflows/tarball/master \
    | tar -xzC /app --strip-component=1 && make \
    && sed -i '/dir\-listing\.activate/s/^#//g' /etc/lighttpd/lighttpd.conf \
    && apk update && apk del build-base && rm /app/src/magic.c
    
#ADD scripts/buildDocker.sh /app/scripts/buildDocker.sh
#ADD scripts/run.sh /app/scripts/run.sh
COPY scripts/* /app/scripts/

RUN chmod +x /app/scripts/buildDocker.sh \
    && chmod +x /app/scripts/run.sh \
    && /app/scripts/buildDocker.sh 

ENTRYPOINT ["/app/scripts/run.sh"]
