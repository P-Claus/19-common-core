FROM debian:11

RUN apt-get update && apt-get install -y mariadb-server \
	&& rm -rf /var/lin/apt/lists/*

EXPOSE 3306
