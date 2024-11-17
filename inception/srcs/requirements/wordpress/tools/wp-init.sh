#!/bin/bash

echo "Waiting for the database..."
until mysql -h mariadb -u pclaus -ppclaus -e "USE mariadb_db;" > /dev/null 2>&1; do
    sleep 10
done
echo "Database is ready."

# Install WordPress and create an admin user
wp core install \
    --url=https://localhost \
    --title=inception \
    --admin_user=pclaus \
    --admin_password=pclaus \
    --admin_email=p@mail.com \
    --allow-root \

