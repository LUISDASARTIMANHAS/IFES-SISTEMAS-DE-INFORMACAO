# ============================================================
# SIMULAÇÃO DO ALGORITMO PERCEPTRON - OPERAÇÃO AND - COM BIAS
# ============================================================


# ------------------------------------------------------------
# 1. FUNÇÃO DE ATIVAÇÃO
# ------------------------------------------------------------
def ativacao(u):
    """
    Função de ativação do Perceptron.

    Se u >= 0, retorna 1.
    Caso contrário, retorna 0.
    """
    if u >= 0:
        return 1
    else:
        return 0


# ------------------------------------------------------------
# 2. CÁLCULO DO ERRO
# ------------------------------------------------------------
def calcular_erro(d, y):
    """
    Calcula o erro:
        e = d - y

    d = saída desejada
    y = saída produzida pelo Perceptron
    """
    return d - y


# ------------------------------------------------------------
# 3. ATUALIZAÇÃO DOS PESOS
# ------------------------------------------------------------
def atualizar_pesos(w1, w2, eta, e, x1, x2):
    """
    Atualiza os pesos do Perceptron:

        w1 = w1 + eta * e * x1
        w2 = w2 + eta * e * x2

    O bias NÃO é alterado porque foi definido como fixo.
    """

    w1 = w1 + eta * e * x1
    w2 = w2 + eta * e * x2

    return w1, w2


# ------------------------------------------------------------
# 4. TREINAMENTO DO PERCEPTRON
# ------------------------------------------------------------
def treinar(dados, eta, w1, w2, b):
    """
    Executa o treinamento do Perceptron até que uma época
    completa seja executada sem nenhum erro.
    """

    epoca = 1

    while True:

        erro_epoca = False

        print("\n" + "=" * 70)
        print(f"ÉPOCA {epoca}")
        print("=" * 70)

        print(f"Pesos iniciais da época:")
        print(f"w1 = {w1}")
        print(f"w2 = {w2}")
        print(f"b  = {b} (fixo)")
        print()

        # Percorre todos os exemplos de treinamento
        for i, (x1, x2, d) in enumerate(dados, start=1):

            # ------------------------------------------------
            # Entrada líquida
            # ------------------------------------------------
            u = x1 * w1 + x2 * w2 + b

            # ------------------------------------------------
            # Saída da rede
            # ------------------------------------------------
            y = ativacao(u)

            # ------------------------------------------------
            # Cálculo do erro
            # ------------------------------------------------
            e = calcular_erro(d, y)

            # ------------------------------------------------
            # Exibição dos cálculos
            # ------------------------------------------------
            print(f"Exemplo {i}")
            print(f"x1 = {x1}, x2 = {x2}, desejado = {d}")

            print(
                f"U = ({x1} * {w1}) + "
                f"({x2} * {w2}) + {b} = {u}"
            )

            print(f"y = {y}")
            print(f"e = {d} - {y} = {e}")

            # ------------------------------------------------
            # Atualização dos pesos
            # ------------------------------------------------
            if e != 0:

                w1, w2 = atualizar_pesos(
                    w1,
                    w2,
                    eta,
                    e,
                    x1,
                    x2
                )

                erro_epoca = True

                print("ERRO! Pesos atualizados:")
                print(f"w1 = {w1}")
                print(f"w2 = {w2}")
                print(f"b  = {b} (fixo)")

            else:

                print("Sem erro. Pesos não foram alterados.")

            print("-" * 50)

        # ----------------------------------------------------
        # Verifica se a época terminou sem erros
        # ----------------------------------------------------
        if not erro_epoca:

            print("\nNenhum erro nesta época.")
            print("Treinamento concluído!")

            break

        epoca += 1

    return w1, w2, b


# ------------------------------------------------------------
# 5. FUNÇÃO PRINCIPAL
# ------------------------------------------------------------
def main():

    # --------------------------------------------------------
    # Configurações
    # --------------------------------------------------------

    # Taxa de aprendizagem
    eta = 1

    # Pesos iniciais
    w1 = 0
    w2 = 0

    # Bias inicial
    # O bias permanece FIXO durante todo o treinamento.
    b = -2

    # --------------------------------------------------------
    # Dados de treinamento da operação AND
    #
    # (x1, x2, saída desejada)
    # --------------------------------------------------------
    dados = [
        (0, 0, 0),
        (0, 1, 0),
        (1, 0, 0),
        (1, 1, 1)
    ]

    # --------------------------------------------------------
    # Inicia o treinamento
    # --------------------------------------------------------
    w1, w2, b = treinar(
        dados,
        eta,
        w1,
        w2,
        b
    )

    # --------------------------------------------------------
    # Resultado final
    # --------------------------------------------------------
    print("\n" + "=" * 70)
    print("PESOS FINAIS")
    print("=" * 70)

    print(f"w1 = {w1}")
    print(f"w2 = {w2}")
    print(f"b  = {b} (fixo)")


# ------------------------------------------------------------
# EXECUÇÃO DO PROGRAMA
# ------------------------------------------------------------
if __name__ == "__main__":
    main()

