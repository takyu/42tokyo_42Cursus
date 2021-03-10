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
		rm $PHPMA_TAR; \
		chown -R www-data:www-data $PHPMA_PATH;

# install wordpress
RUN set -ex; \
		wget --no-check-certificate https://wordpress.org/latest.tar.gz; \
		tar -xvzf latest.tar.gz -C /var/www/html/; \
		rm latest.tar.gz; \
		chown -R www-data:www-data /var/www/html/wordpress;

# copy files of srcs directries
COPY ./srcs/supervisord.conf /etc/supervisor/conf.d/supervisord.conf

# keep move(after delete)
CMD tail -f /dev/null

# Specify the port number
EXPOSE 80 443