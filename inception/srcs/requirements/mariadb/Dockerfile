FROM debian:11

RUN apt-get update && apt-get install -y mariadb-server \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld

RUN mkdir -p /docker-entrypoint-initdb.d

COPY mariadb.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY init.sql /docker-entrypoint-initdb.d

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

CMD ["mysqld", "--datadir=/var/lib/mysql", "--init-file=/docker-entrypoint-initdb.d/init.sql"]
