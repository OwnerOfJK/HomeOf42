FROM debian:latest

RUN apt update && apt upgrade && apt install -y php-fpm php-mysqli curl
# php-fpm: PHP FastCGI Process Manager.
# php-mysqli: MySQLi extension for PHP. so that we can access mariadb.
# curl: to download and install wordpress site.

COPY www.conf /etc/php/8.2/fpm/pool.d/www.conf
# Here we overwrite the default configuration file with our own configuration file.

COPY init_wp.sh .
RUN chmod +x init_wp.sh
# copy the script to the container and make it executable.

CMD ["./init_wp.sh"]
#CMD ["php-fpm8.2", "-F"]