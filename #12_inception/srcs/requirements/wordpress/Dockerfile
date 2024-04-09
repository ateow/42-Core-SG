FROM debian:bookworm

RUN apt-get update && apt-get -y install \
	mariadb-client \
	wget \
	curl \
	bash \
	php \
	php-cgi \
	php-mysql \
	php-fpm \
	php-pdo \
	php-gd php-cli \
	php-mbstring
	
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /etc/php/8.2/fpm
COPY ./www.conf /etc/php/8.2/fpm/pool.d

RUN mkdir -p /run/php

COPY ./create_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wordpress.sh
RUN ls /run/php
WORKDIR /var/www/html

ENTRYPOINT ["/usr/local/bin/create_wordpress.sh"]

EXPOSE 9000
	
# ENTRYPOINT is like setting the main command that the container should always run.
# CMD is like providing default options or a default command that can be overridden if needed.
