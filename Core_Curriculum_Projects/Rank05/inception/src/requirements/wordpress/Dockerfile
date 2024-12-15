FROM debian:bullseye

RUN apt update && apt upgrade -y && \
    apt install -y \
    php7.4-fpm \
    php7.4-mysqli \
    php7.4-mysql \
    mariadb-client \
    curl

# Create the necessary directory for PHP-FPM
RUN mkdir -p /run/php

# Copy the configuration file for PHP-FPM
COPY ./config/www.conf /etc/php/7.4/fpm/pool.d/www.conf

# Copy the initialization script and make it executable
COPY ./script/init_wp.sh .
RUN chmod +x init_wp.sh

CMD ["./init_wp.sh"]
