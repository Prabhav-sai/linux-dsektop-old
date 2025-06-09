from flask import Flask, render_template, request, redirect, url_for, flash,make_response
import hashlib
import json

app = Flask(__name__)

user = dict.fromkeys(['username','email','password'],None)

@app.route("/")
def view():
    return render_template("form.html")


@app.route('/input',methods=['POST'])
def take_input():
    hash_object = hashlib.sha256()
    user['username'] = request.form['username']
    user['email'] = request.form['email']
    password = request.form['password']
    hash_object.update(password.encode())
    user['password'] = hash_object.hexdigest()
    json_user = json.dumps(user)
    print(json_user)
    with open("users.txt",'a') as userstext:
        userstext.write(json_user+"\n")
    return "SUCCESS!!!!"

@app.route('/user/<user_id>')
def output(user_id):
    str = ""
    with open("users.txt",'r') as userstext:
        for line in userstext:
            obj = json.loads(line)
            if(obj.get("email")==user_id):
                str = "Username:"+ obj.get("username")+"\n"
                str += "Email:"+ obj.get("email")+"\n"
                str +="Password:"+ obj.get("password")+"\n"
                break
            else:
                str ="user not found!!!!"
    response = make_response(str)
    response.headers['Content-Type'] = 'text/plain'
    return response

if __name__ == "__main__":
    app.run()