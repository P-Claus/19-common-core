#!/bin/bash

RETRY_COUNT=0
MAX_RETRIES=5

while [ "$RETRY_COUNT" -lt "$MAX_RETRIES" ]; do
    if mysql -h $WORDPRESS_DB_HOST -u $MYSQL_USER -p$MYSQL_PASSWORD -e "USE $WORDPRESS_DB_NAME;" > /dev/null 2>&1; then
        echo "Database is ready."
        break
    else
        echo "Attempt $((++RETRY_COUNT)): Database is not ready yet. Retrying in 5 seconds..."
        sleep 5
    fi
done

cat <<EOF > /var/www/html/wp-config.php
<?php

define('WPLANG', 'en_US');
define('DB_NAME', $MYSQL_DATABASE);
define('DB_USER', $MYSQL_USER);
define('DB_PASSWORD', $MYSQL_PASSWORD);
define('DB_HOST', $WORDPRESS_DB_HOST);
define('DB_CHARSET', 'utf8mb4');
define('DB_COLLATE', '');

define('WP_HOME', 'https://pclaus.19.be');
define('WP_SITEURL', 'https://pclaus.19.be');

define('AUTH_KEY', 'put your unique phrase here');
define('SECURE_AUTH_KEY', 'put your unique phrase here');
define('LOGGED_IN_KEY', 'put your unique phrase here');
define('NONCE_KEY', 'put your unique phrase here');
define('AUTH_SALT', 'put your unique phrase here');
define('SECURE_AUTH_SALT', 'put your unique phrase here');
define('LOGGED_IN_SALT', 'put your unique phrase here');
define('NONCE_SALT', 'put your unique phrase here');

\$table_prefix = 'wp_';

define('WP_DEBUG', true);

define('FORCE_SSL_ADMIN', true);

define('WP_DEBUG_LOG', true);
define('WP_DEBUG_DISPLAY', true);

define('WP_CONTENT_DIR', '/var/www/html/wp-content');
define('WP_CONTENT_URL', 'https://pclaus.19.be/wp-content');


if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}
require_once( ABSPATH . 'wp-settings.php' );

EOF

if ! wp core is-installed --allow-root --path=/var/www/html; then
    echo "Installing WordPress..."
    wp core install \
        --url="http://pclaus.19.be" \
        --title="Inception" \
        --admin_user=$WORDPRESS_ADMIN_USERNAME \
        --admin_password=$WORDPRESS_ADMIN_PASSWORD \
        --admin_email=$WORDPRESS_ADMIN_EMAIL \
        --allow-root \
        --path=/var/www/html
    echo "WordPress installed successfully."
else
    echo "WordPress is already installed."
fi

if ! wp user exists $WORDPRESS_USER_USERNAME --allow-root --path=/var/www/html; then
	echo "Adding user...." 
	wp user create $WORDPRESS_USER_USERNAME $WORDPRESS_USER_EMAIL \
    --role=author \
    --user_pass=$WORDPRESS_USER_PASSWORD \
    --allow-root \
    --path=/var/www/html
	echo "User $WORDPRESS_USER_USERNAME added."
else
	echo "User $WORDPRESS_USER_USERNAME already exists"
fi

echo "Running PHP-FPM..."
exec php-fpm7.4 -F
