CREATE DATABASE mariadb_db;
CREATE USER 'pclaus'@'%' IDENTIFIED BY 'pclaus';
GRANT ALL PRIVILEGES ON mariadb_db.* TO 'pclaus'@'%';
FLUSH PRIVILEGES;
