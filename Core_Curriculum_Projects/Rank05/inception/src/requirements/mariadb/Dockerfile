FROM debian:latest

RUN apt update && apt upgrade && apt install -y mariadb-server

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
# Here we overwrite the default configuration file with our own configuration file.

COPY init.sql /etc/mysql/init.sql
COPY init_db.sh .

RUN mkdir /run/mysqld && chmod +x init_db.sh

CMD ["./init_db.sh"]
# mysqld: starts the MariaDB server.