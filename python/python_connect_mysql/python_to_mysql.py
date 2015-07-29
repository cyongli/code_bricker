#!/usr/bin/python

import mysql.connector

cnx = mysql.connector.connect(user='root', database='palo_test', host='10.74.167.16', port='9430')
cursor = cnx.cursor()

query = 'select d_datekey, d_month, d_year from dates limit 1,5' 

cursor.execute(query)
#result = cursor.fetchone()
#print result
for (d_datekey, d_year, d_yearmonthnum) in cursor:
	print d_datekey, "\t", d_year, "\t", d_yearmonthnum


cursor.close()
cnx.close()
