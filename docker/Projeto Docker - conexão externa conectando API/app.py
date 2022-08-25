from crypt import methods
from distutils.log import debug
import flask
from flask import request, json, jsonify

import requests

#Iniciando o Flask
app = flask.Flask(__name__)

#Ver mensagens no terminal
app.config["DEBUG"] = True

#Adicionando método GET para uma rota, e assim consumir os dados da API randomuser(grátis -> api de código abreto que tem dados de usuário fictícios)
@app.route("/", methods=["GET"])

#Função para pegar os dados na API
def index():
    data = requests.get("https://randomuser.me/api")
    return data.json()

if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True, port="5000")

