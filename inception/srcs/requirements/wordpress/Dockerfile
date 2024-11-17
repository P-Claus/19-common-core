FROM debian:11

RUN apt-get update && apt-get install -y --no-install-recommends php-mysql php-fpm wget unzip ca-certificates \
	&& apt install curl -y \
	less \
	&& apt-get install mariadb-client -y \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php /var/www/html

COPY tools/config.php /var/www/html/wp-config.php

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

COPY tools/wp-init.sh /usr/local/bin/startup.sh
RUN chmod +x /usr/local/bin/startup.sh

RUN wp core download --path=/var/www/html --allow-root

RUN sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/' /etc/php/7.4/fpm/php.ini && \
    echo "listen = 9000" >> /etc/php/7.4/fpm/pool.d/www.conf

RUN chown -R www-data:www-data /var/www/html



RUN chown -R www-data:www-data /var/www/html && \
    chmod -R 755 /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/startup.sh"]
