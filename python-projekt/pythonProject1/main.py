from flask import Flask, render_template
from flask_restful import Api

app = Flask(__name__)
api = Api(app)

@app.route('/', methods=['GET'])
def test():
    with open('data.txt') as f:
        temp = f.readline()
    return render_template('test.html', value=temp)

if __name__ == "__main__":
    app.run(port = 8000, debug = True)

