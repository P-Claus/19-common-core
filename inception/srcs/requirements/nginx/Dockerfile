FROM debian:11

RUN apt-get update && apt-get install -y --no-install-recommends nginx openssl \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl /var/log/nginx \
    && chmod -R 755 /var/log/nginx

RUN mkdir -p /etc/nginx/ssl

COPY ../tools/ssl/example.crt /etc/nginx/ssl/example.crt
COPY ../tools/ssl/example.key /etc/nginx/ssl/example.key

COPY nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]

