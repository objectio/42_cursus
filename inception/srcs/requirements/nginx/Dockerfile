FROM debian:buster

RUN apt-get update && \
        apt-get upgrade -y

RUN apt-get install nginx -y

WORKDIR /tmp/
ENV BUILDDIR=/tmp/build/
RUN mkdir ${BUILDDIR}

COPY src/ ${WORKDIR}

