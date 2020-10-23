import pymysql

class Database:
    def __init__(self):
        host = "127.0.0.1"
        user = "root"
        password = "password"
        db = "epytodo"
        self.con = pymysql.connect(host=host, user=user, password=password, db = db, cursorclass=pymysql.cursors.DictCursor)
        self.cur = self.con.cursor()

    def list_user(self):
        sql = "SELECT * from user"
        self.cur.execute(sql)
        self.con.commit()
        result = self.cur.fetchall()
        return result

    def add_user(self, username, password):
        sql = "INSERT INTO user(username, password) VALUES ( '"+username+"', '"+password+"')"
        self.cur.execute(sql)
        self.con.commit()
        result = self.cur.fetchone()
        return result

    def sign_in(username, password):
        sql = "SELECT username, password from user WHERE password='"+password+"' AND username='"+username+"'"
        self.cur.execute(sql)
        self.con.commit()
        result = self.cur.fetchone()
        return result