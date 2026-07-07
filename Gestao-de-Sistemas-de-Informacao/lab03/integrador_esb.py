class IntegradorESB:
    """Mini barramento ESB para traduzir dados entre sistemas legados."""

    @staticmethod
    def transformar_rh_para_financeiro(dados_rh):
        """Converte o contrato do RH para o contrato esperado pelo Financeiro."""
        # Aqui garantimos que o significado seja preservado na tradução.
        return {
            "cod": dados_rh["id_func"],
            "valor": dados_rh["salario_base"],
        }
