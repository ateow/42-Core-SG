FROM debian:bullseye

RUN apt-get update \
	&& apt-get -y install mariadb-server mariadb-client \
	&& mysql_secure_installation

# mysql_secure_installation is a post script that initialise parameters for better security


#initalise Database
RUN mysql_install_db 


EXPOSE	3306

CMD ["mysqld_safe"]

