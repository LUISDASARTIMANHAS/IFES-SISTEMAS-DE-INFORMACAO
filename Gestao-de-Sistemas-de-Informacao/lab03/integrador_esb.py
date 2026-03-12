# lab3/integrador_esb.py
class IntegradorESB:
    @staticmethod
    def transformar_rh_para_financeiro(dados_rh):
    # Aqui garantimos que o significado (Semântica) seja preservado na tradução
        return {
        "cod": dados_rh["id_func"],
        "valor": dados_rh["salario_base"]
    }

# Fluxo de Integração
# dados_convertidos = IntegradorESB.transformar_rh_para_financeiro(funcionario_rh)
# processar_pagamento(dados_convertidos) # Agora funciona!