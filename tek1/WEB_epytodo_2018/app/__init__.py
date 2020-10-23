from flask import Flask, json
import os

app = Flask(__name__)
app.config.from_object('config')
app.secret_key = os.urandom(12)

from app import views