# lab3/microservico_eping.py
# ============================================================
# LABORATÓRIO 3 - PARTE 3
# API REST e Microserviço seguindo padrão ePING
# ============================================================

"""
Este script simula um Microserviço Governamental
seguindo o padrão ePING (Arquitetura de Interoperabilidade do Governo).

Aqui ocorre:

- INTEROPERABILIDADE TÉCNICA:
  Uso de HTTP + JSON como protocolo padrão.

- INTEROPERABILIDADE SEMÂNTICA:
  Estrutura padronizada dos dados (cpf, nome, status).

- MODULARIZAÇÃO:
  O serviço funciona de forma independente dos sistemas consumidores.
"""

from flask import Flask, jsonify

app = Flask(__name__)

# ------------------------------------------------------------
# Base de dados simulada (Contrato Padronizado)
# ------------------------------------------------------------
database = {
    1: {
        "cpf": "123.456.789-00",
        "nome": "Eduardo Amaral",
        "status": "Ativo"
    },
    2: {
        "cpf": "987.654.321-00",
        "nome": "Maria Silva",
        "status": "Inativo"
    }
}

# ------------------------------------------------------------
# Endpoint REST
# ------------------------------------------------------------
@app.route('/api/cidadao/<int:id>', methods=['GET'])
def get_cidadao(id):
    """
    Endpoint que retorna dados padronizados.
    O contrato da API garante interoperabilidade semântica.
    """
    cidadao = database.get(id, {"erro": "Não encontrado"})
    return jsonify(cidadao)

# simulaçao de um microserviço ePING que pode ser consumido por diversos sistemas
# curl http://localhost:5000/api/cidadao/1

# ------------------------------------------------------------
# Execução do Serviço
# ------------------------------------------------------------
if __name__ == '__main__':
    print("======================================")
    print("Serviço ePING rodando na porta 5000...")
    print("Acesse: http://localhost:5000/api/cidadao/1")
    print("======================================")
    app.run(port=5000)