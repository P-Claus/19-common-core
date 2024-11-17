#!/bin/bash
set -e

# Wait for the database to be ready
until mysql -h mariadb -upclaus -ppclaus -e 'SELECT 1'; do
  >&2 echo "MariaDB is unavailable - sleeping"
  sleep 3
done

# Run wp-cli command to install and activate the language
wp core language install en_US --activate --path=/var/www/html --allow-root

# Execute the CMD
exec "$@"