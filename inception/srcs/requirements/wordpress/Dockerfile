FROM debian:11

RUN apt-get update && apt-get install -y --no-install-recommends php-fpm wget unzip ca-certificates\
	&& rm -rf /var/lib/apt/lists/*

RUN wget https://wordpress.org/wordpress-5.8.1.zip -O /tmp/wordpress.zip && \
    unzip /tmp/wordpress.zip -d /var/www/ && \
    rm /tmp/wordpress.zip

RUN sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/' /etc/php/7.4/fpm/php.ini && \
    echo "listen = 9000" >> /etc/php/7.4/fpm/pool.d/www.conf

RUN chown -R www-data:www-data /var/www/wordpress

EXPOSE 9000

CMD ["php-fpm7.4", "-F"]