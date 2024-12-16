#!/bin/bash
cd /var/www/html

# Wait for MariaDB to be ready
while ! mysql -h$WORDPRESS_DB_HOST -u$WORDPRESS_DB_USER -p$PASSWORD -e "SELECT 1;" >/dev/null 2>&1; do
    echo "Waiting for MariaDB to be ready..."
    sleep 5
done

if [ ! -f "wp-config.php" ]; then

    # Clean existing files
    rm -rf *

    # Download WordPress
    echo "Downloading WordPress..."
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar

    # Create wp-config.php
    echo "Creating wp-config.php..."
    ./wp-cli.phar core download --allow-root || exit 1

    ./wp-cli.phar config create \
        --dbname=$WORDPRESS_DB_NAME \
        --dbuser=$WORDPRESS_DB_USER \
        --dbpass=$PASSWORD \
        --dbhost=$WORDPRESS_DB_HOST \
        --allow-root || exit 1

    # Install WordPress
    echo "Installing WordPress..."
    ./wp-cli.phar core install \
        --url=$DOMAIN_NAME \
        --title=$WORDPRESS_TITLE \
        --admin_user=$WORDPRESS_ADMIN_USER \
        --admin_password=$PASSWORD \
        --admin_email=$WORDPRESS_ADMIN_EMAIL \
        --allow-root || exit 1

    # Install themes
    echo "Installing themes..."
    ./wp-cli.phar theme install twentytwentythree --activate --allow-root
    ./wp-cli.phar theme install astra --activate --allow-root

    # Create WordPress users
    echo "Creating a subscriber user..."
    ./wp-cli.phar user create akaller akaller@42.com --role=subscriber --user_pass=$USER_PASSWORD --allow-root
fi

# Start PHP-FPM (use the correct version for your Debian)
php-fpm7.4 -F