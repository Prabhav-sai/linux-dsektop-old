import pymysql

hostname = 'localhost'
user = 'prabhav'
password = 'Prabhav123!'

db = pymysql.connections.Connection(
    host=hostname,
    user=user,
    password=password
)

cursor = db.cursor()
cursor.execute("CREATE DATABASE IF NOT EXISTS books_db")
cursor.execute("SHOW DATABASES")

for databases in cursor:
    print(databases)

# Closing the cursor and connection to the database
cursor.close()
db.close()


from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

# Configuring the Flask app to connect to the MySQL database
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql+pymysql://root:your_password@localhost/books_db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

# Creating an instance of the SQLAlchemy class
db = SQLAlchemy(app)


# Defining the Book model
class Book(db.Model):
    # Specifying the table name
    __tablename__ = 'books'

    # Specifying the columns and their data types
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(100), nullable=False)
    author = db.Column(db.String(50), nullable=False)
    genre = db.Column(db.String(20), nullable=False)

    # Defining the constructor method
    def __init__(self, title, author, genre):
        self.title = title
        self.author = author
        self.genre = genre

    # Defining the __repr__ method
    def __repr__(self):
        return f'<Book {self.title}>'


