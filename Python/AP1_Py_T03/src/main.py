from flask import Flask
from Controller.controller import Controller

def main():
    app = Flask(__name__)
    app.run()
    contr = Controller()
    contr.start()

if __name__ == "__main__":
    main()
