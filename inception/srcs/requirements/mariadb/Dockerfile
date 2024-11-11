FROM debian:11

RUN apt-get update && apt-get install -y mariadb-server \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld

RUN mkdir -p /docker-entrypoint-initdb.d

COPY mariadb.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY init.sql /docker-entrypoint-initdb.d

CMD ["bash", "-c", "mysqld --datadir=/var/lib/mysql & \
    sleep 3 && \
    mysql -u root -proot < /docker-entrypoint-initdb.d/init.sql && \
    wait"]
