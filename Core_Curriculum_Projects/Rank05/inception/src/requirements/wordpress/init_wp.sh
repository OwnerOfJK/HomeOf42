#!/bin/bash
cd /var/www/html
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
./wp-cli.phar core download --allow-root
./wp-cli.phar config create --dbname=wordpress --dbuser=wpuser --dbpass=password --dbhost=mariadb --allow-root
./wp-cli.phar core install --url=localhost --title=inception --admin_user=jkaller --admin_password=Jkaller42!!! --admin_email=jkaller@42.de --allow-root
./wp-cli.phar theme install twentytwentythree --activate --allow-root
./wp-cli.phar theme install astra --activate --allow-root

php-fpm8.2 -F