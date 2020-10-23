from app import models
from app import json
from flask import request
from flask import session


SIGN_IN_RES = { "result" : "signin successful"}
SIGN_IN_ERR_USER = { "error" : "login or password does not match"}
SIGN_IN_ERR_INT = { "error" : "internal error"}
REGISTER_RES = {"result" : "account created"}
REGISTER_ERR_USER = {"error" : "account already exist"}
REGISTER_ERR_INT =  { "error" : "internal error"}

def add_user():
    if "username" not in request.json and "password" not in request.json:
        return REGISTER_ERR_INT
    username, password = request.json["username"], requiest.json["password"]
    result = models.Database.add_user(username, password)
    if result != 0:
        return REGISTER_ERR_USER
    else:
        return REGISTER_RES

def sign_in():
    if "username" not in request.json and "password" not in request.json:
        return SIGN_IN_ERR_INT
    username, password = request.json['username'], request.json['password']
    result = models.sign_in(username, password)
    if result != 0:
        return SIGN_IN_ERR_USER
    else:
        session['logged_in'] = True
        return SIGN_IN_RES
