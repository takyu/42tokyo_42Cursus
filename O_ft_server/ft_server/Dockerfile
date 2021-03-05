# linux distribution
FROM debian:buster

# author field of the built images
LABEL maintainer="tnagoshi <tnagoshi@student.42tokyo.jp>"

# install tools
RUN set -ex; \
    apt-get update; \
    apt-get install -y --no-install-recommends \
        wget \
        vim \
        openssl \
        supervisor \
        nginx \
        mariadb-server mariadb-client \
        php-cgi php-common php-fpm php-pear php-mbstring php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath; \
    rm -rf /var/lib/apt/lists/*

# configure a wordpress database

# install wordpress

# install mariadb

# copy files of srcs directries
COPY ./srcs/supervisord.conf /etc/supervisor/conf.d/supervisord.conf

# Specify the port number
EXPOSE 80 443