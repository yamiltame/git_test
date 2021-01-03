import sqlite3

db=sqlite3.connect('popstore.db')
db.execute("create table if not exists Productos ('id' integer primary key autoincrement,'tipo' int,'nombre' text,'cantidad' int)") 
db.execute("create table if not exists Materia ('id' integer primary key autoincrement,'nombre' text,'cantidad' int)") 

