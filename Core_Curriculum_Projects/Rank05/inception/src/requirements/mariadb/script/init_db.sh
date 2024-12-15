#!/bin/bash

# Ensure directory exists and has correct permissions
mkdir -p /var/run/mysqld
chown -R mysql:mysql /var/run/mysqld
chmod 777 /var/run/mysqld

# Initialize the MySQL data directory
if [ ! -d "/var/lib/mysql/mysql" ]; then
    # Initialize MySQL system tables
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    # Start MySQL server temporarily
    mysqld --user=mysql --bootstrap

    cat << EOF > /etc/mysql/init.sql
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$PASSWORD';
FLUSH PRIVILEGES;
EOF
fi

# Start mysqld
exec mysqld --user=mysql