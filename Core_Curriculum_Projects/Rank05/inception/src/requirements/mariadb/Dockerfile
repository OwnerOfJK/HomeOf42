FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y mariadb-server

# Create necessary directories and set permissions
RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 777 /var/run/mysqld \
    && mkdir -p /var/lib/mysql \
    && chown -R mysql:mysql /var/lib/mysql

# RUN mkdir workdir
# WORKDIR /workdir

# Copy configurations
COPY ./config/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy and make init script executable
COPY ./script/init_db.sh .
RUN chmod +x init_db.sh 

CMD ["./init_db.sh"]