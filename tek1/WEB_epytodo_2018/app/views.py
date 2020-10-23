from app import app
from flask import session
from app.controller import sign_in, add_user
from flask import render_template

@app.route('/', methods=['GET'])
def route_index():
    return render_template("index.html",
                            title="EpyTodo",
                            home="Welcome"
                            )

@app.route('/register', methods=['POST'])
def route_register():
    return render_template("index.html",
                            title="EpyTodo Registration",
                            home=""
                            )

@app.route('/signin', methods=['POST'])
def route_signin():
    result = sign_in
    return render_template("index.html",
                            title="EpyTodo SignIn",
                            home=""
                            )

@app.route('/signout', methods=['POST'])
def route_signout():
    return render_template("index.html",
                            title="EpyTodo SignOut",
                            home=""
                            )

@app.route('/user/<username>', methods=['GET'])
def route_user_(username):
    return render_template("board.html",
                            title="EpyTodo",
                            home="Welcome "+username
                            ) 

@app.route('/user', methods=['GET'])
def route_user():
    return render_template("board.html",
                            title="EpyTodo",
                            home=""
                            )

@app.route('/user/task', methods=['GET', 'POST'])
def route_usertask():
    return render_template("board.html",
                            title="EpyTodo",
                            home=""
                            )

@app.route('/user/task/id', methods=['GET'])
def route_usertaskid():
    return render_template("board.html",
                            title="EpyTodo",
                            home=""
                            )

@app.route('/user/task/add', methods=['POST'])
def route_usertaskadd():
    return render_template("board.html",
                            title="EpyTodo",
                            home=""
                            )

@app.route('/user/task/del/id', methods=['POST'])
def route_usertaskdel():
    return render_template("board.html",
                            title="EpyTodo",
                            home=""
                            )

