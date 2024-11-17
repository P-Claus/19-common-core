#!/bin/bash

set -e

# Ensure the database is ready before proceeding
# Initialize a counter to track retries
RETRY_COUNT=0
MAX_RETRIES=0 # Set this to a non-zero value if you want to limit retries

while true; do
    if mysql -h mariadb -u pclaus -ppclaus -e "USE mariadb_db;" > /dev/null 2>&1; then
        echo "Database is ready."
        break
    else
        echo "Attempt $((++RETRY_COUNT)): Database is not ready yet. Retrying in 5 seconds..."
        sleep 5
    fi
    
    # Uncomment this block if you want to limit the number of retries
    # if [ $MAX_RETRIES -ne 0 ] && [ $RETRY_COUNT -ge $MAX_RETRIES ]; then
    #     echo "Database connection failed after $MAX_RETRIES attempts. Exiting..."
    #     exit 1
    # fi
done

# Check if WordPress is already installed
if ! wp core is-installed --allow-root --path=/var/www/html; then
    echo "Installing WordPress..."
    wp core install \
        --url="http://pclaus.19.be" \
        --title="Inception" \
        --admin_user="pclaus" \
        --admin_password="pclaus" \
        --admin_email="email@example.com" \
        --allow-root \
        --path=/var/www/html
    echo "WordPress installed successfully."
else
    echo "WordPress is already installed."
fi

wp user create Bob bob@gmail.com --role=author --user_pass=bob --allow-root --path=/var/www/html

# Start PHP-FPM
php-fpm7.4 -F

