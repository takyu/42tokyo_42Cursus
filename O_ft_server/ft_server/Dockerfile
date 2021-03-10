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
ENV DB_NAME="wpdb" \
	DB_USER="wpuser" \
	DB_HOST="localhost" \
	DB_PASS="dbpassword"

RUN set -ex; \
		service mysql start; \
			mysql -e "CREATE DATABASE $DB_NAME;"; \
			mysql -e "CREATE USER '$DB_USER'@'$DB_HOST' identified by '$DB_PASS';"; \
			mysql -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'$DB_HOST';"; \
			mysql -e "FLUSH PRIVILEGES;";

# install phpmyadmin

ENV PHPMA_PATH="var/www/html/phpmyadmin" \
	PHPMA_TAR="phpMyAdmin-5.0.2-all-languages.tar.gz"

RUN set -ex; \
		mkdir $PHPMA_PATH; \
		wget --no-check-certificate https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz; \
		tar -xvzf $PHPMA_TAR -C $PHPMA_PATH --strip-components=1; \
		rm $PHPMA_TAR;

# install wordpress
RUN set -ex; \
		wget --no-check-certificate https://wordpress.org/latest.tar.gz; \
		tar -xvzf latest.tar.gz -C /var/www/html/; \
		rm latest.tar.gz;

# change owner of var/www/html/*
RUN chown -R www-data:www-data var/www/html/*;

# Issue an SSL certificate and turn on SSL settings in nginx
ENV SSL_PATH="etc/nginx/ssl" \
	SSL_KEY="server.key" \
	SSL_CSR="server.csr" \
	SSL_CRT="server.crt"

RUN set -ex; \
		mkdir $SSL_PATH; \
		openssl genrsa -out $SSL_PATH/$SSL_KEY 2048; \
		openssl req -new \
			-key $SSL_PATH/$SSL_KEY \
			-out $SSL_PATH/$SSL_CSR \
			-subj "/C=JP/ST=Tokyo/L=Minato-ku/O=DMM/OU=42Tokyo/CN=localhost"; \
		openssl x509 -req \
			-in $SSL_PATH/$SSL_CSR \
			-days 3650 \
			-signkey $SSL_PATH/$SSL_KEY \
			-out $SSL_PATH/$SSL_CRT;

# copy files of srcs directries
COPY ./srcs/supervisord.conf /etc/supervisor/conf.d/supervisord.conf
COPY ./srcs/wp-config.php /var/www/html/wordpress/wp-config.php
COPY ./srcs/default.tmpl /etc/nginx/sites-available/default.tmpl

# install entrykit
ENV EK_TAR="entrykit_0.4.0_Linux_x86_64.tgz"
RUN set -ex; \
	wget --no-check-certificate https://github.com/progrium/entrykit/releases/download/v0.4.0/entrykit_0.4.0_Linux_x86_64.tgz; \
	tar -xvzf $EK_TAR -C /bin; \
	rm $EK_TAR; \
	chmod +x /bin/entrykit; \
	entrykit --symlink;

# add execution authority to supervisord.conf
RUN	chmod +x /etc/supervisor/conf.d/supervisord.conf;

# exec entrypoint
ENTRYPOINT ["render", "/etc/nginx/sites-available/default", "--", "/usr/bin/supervisord"]

# Specify the port number
EXPOSE 80 443