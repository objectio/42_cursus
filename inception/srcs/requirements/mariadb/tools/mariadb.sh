#!/bin/sh

mysql_install_db

/etc/init.d/mysql start

#Check if the database exists

if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then 

	echo "Database already exists"
else

# Set root option so that connexion without root password is not possible

#Add a root user on 127.0.0.1 to allow remote connexion 
#Flush privileges allow to your sql tables to be updated automatically when you modify it
#mysql -uroot launch mysql command line client

#Create database and user in the database for wordpress

echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; FLUSH PRIVILEGES;" | mysql

#Import database in the mysql command line
mysql $MYSQL_DATABASE < /usr/local/bin/wordpress.sql

echo "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MYSQL_ROOT_PASSWORD');" | mysql

fi

/etc/init.d/mysql stop

exec "$@"
