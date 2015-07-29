#!/usr/bin/python
import MySQLdb

db = MySQLdb.connect(host="10.74.167.16", 
                port=9430, 
				user="root",
				db="palo_test")

# you must create a Cursor object. It will let
		#  you execute all the queries you need
cur = db.cursor() 

# Use all the SQL you like
query = 'select siteid, stat_time, sitestatus from visit_browser limit 1,5';
cur.execute(query)

for res in cur:
    print res

cur.close()
db.close()
