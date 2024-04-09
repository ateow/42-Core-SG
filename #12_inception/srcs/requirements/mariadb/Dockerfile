FROM debian:buster

RUN apt-get update && apt-get install -y \
	mariadb-server mariadb-client
	
#initalise Database
RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf
COPY my.conf /etc/mysql/mariadb.conf.d
RUN mysql_install_db 

ARG DB_NAME=${MYSQL_DATABASE}
ARG DB_USER=${MYSQL_USER}
ARG DB_PASSWORD=${MYSQL_PASSWORD}
ARG DB_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}

COPY ./init_db.sh /
RUN chmod +x ./init_db.sh
RUN bash ./init_db.sh
RUN service mysql stop

EXPOSE 3306

CMD ["mysqld_safe"]


