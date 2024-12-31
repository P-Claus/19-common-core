#!/bin/bash

RETRY_COUNT=0
MAX_RETRIES=5

while [ "$RETRY_COUNT" -lt "$MAX_RETRIES" ]; do
    if mysql -h mariadb -u pclaus -ppclaus -e "USE mariadb_db;" > /dev/null 2>&1; then
        echo "Database is ready."
        break
    else
        echo "Attempt $((++RETRY_COUNT)): Database is not ready yet. Retrying in 5 seconds..."
        sleep 5
    fi
done


if ! wp core is-installed --allow-root --path=/var/www/html; then
    echo "Installing WordPress..."
    wp core install \
        --url="http://pclaus.19.be" \
        --title="Inception" \
        --admin_user="pclaus" \
        --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
        --admin_email="email@example.com" \
        --allow-root \
        --path=/var/www/html
    echo "WordPress installed successfully."
else
    echo "WordPress is already installed."
fi

if ! wp user exists Bob --allow-root --path=/var/www/html; then
	echo "Adding user...." 
	wp user create Bob bob@gmail.com \
    --role=author \
    --user_pass="$WORDPRESS_BOB_PASSWORD" \
    --allow-root \
    --path=/var/www/html
	echo "User Bob added."
else
	echo "User Bob already exists"
fi

echo "Starting PHP-FPM..."
exec php-fpm7.4 -F
