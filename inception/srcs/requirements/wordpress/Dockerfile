FROM debian:11

RUN apt-get update && apt-get install -y --no-install-recommends php-mysql php-fpm wget unzip ca-certificates \
	&& apt install curl -y \
	less \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php /var/www/html

RUN wget https://wordpress.org/wordpress-6.0.9.zip -O /tmp/wordpress.zip && \
    unzip /tmp/wordpress.zip -d /var/www/html && \
    rm /tmp/wordpress.zip

RUN sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/' /etc/php/7.4/fpm/php.ini && \
    echo "listen = 9000" >> /etc/php/7.4/fpm/pool.d/www.conf

RUN chown -R www-data:www-data /var/www/html

COPY tools/config.php /var/www/html/wordpress/wp-config.php

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

#COPY tools/wp-init.sh /usr/local/bin/wp-init.sh

#RUN chmod +x /usr/local/bin/wp-init.sh

EXPOSE 9000

CMD ["php-fpm7.4", "-F"]
