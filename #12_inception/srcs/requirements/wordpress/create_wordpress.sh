#!/bin/sh

#check if wp-config.php exist
if [ -f ./wp-config.php ]
then
	echo "wordpress present"
else
	cd /var/www/html

	#Download wordpress and all config file
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* .
	rm -rf latest.tar.gz
	rm -rf wordpress

	#Import env variables in the config file
	#sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	#sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	#sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	#sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	#cp wp-config-sample.php wp-config.php
	
	wp core config "--dbhost=$MYSQL_HOSTNAME" \
		        "--dbname=$MYSQL_DATABASE" \
		        "--dbuser=$MYSQL_USER" \
		        "--dbpass=$MYSQL_PASSWORD" \
		        "--allow-root"

	wp core install "--title=$WP_TITLE" \
		        "--admin_user=$WP_ADMIN_USER" \
		        "--admin_password=$WP_ADMIN_PASSWORD" \
		        "--admin_email=$WP_ADMIN_MAIL" \
		        "--url=$WP_URL" \
		        "--allow-root"
fi

php-fpm8.2 -F
