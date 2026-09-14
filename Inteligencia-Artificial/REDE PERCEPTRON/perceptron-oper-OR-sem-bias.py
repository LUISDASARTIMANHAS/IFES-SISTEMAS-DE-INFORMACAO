# ============================================================
# SIMULAÇÃO DO ALGORITMO PERCEPTRON - OPERAÇÃO OR - SEM BIAS
# ============================================================


# ------------------------------------------------------------
# 1. FUNÇÃO DE ATIVAÇÃO
# ------------------------------------------------------------
def ativacao(u):
    """
    Função de ativação do Perceptron.

    Se u > 0, retorna 1.
    Caso contrário, retorna 0.

    @param u Entrada líquida.
    @return Saída produzida pelo Perceptron.
    """
    if u > 0:
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

    @param d Saída desejada.
    @param y Saída produzida pelo Perceptron.
    @return Erro calculado.
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

    O Perceptron não possui bias.

    @param w1 Peso da entrada x1.
    @param w2 Peso da entrada x2.
    @param eta Taxa de aprendizagem.
    @param e Erro.
    @param x1 Primeira entrada.
    @param x2 Segunda entrada.
    @return Novos valores de w1 e w2.
    """

    w1 = w1 + eta * e * x1
    w2 = w2 + eta * e * x2

    return w1, w2


# ------------------------------------------------------------
# 4. TREINAMENTO DO PERCEPTRON
# ------------------------------------------------------------
def treinar(dados, eta, w1, w2):
    """
    Executa o treinamento do Perceptron até que uma época
    completa seja executada sem nenhum erro.

    @param dados Dados de treinamento.
    @param eta Taxa de aprendizagem.
    @param w1 Peso inicial da entrada x1.
    @param w2 Peso inicial da entrada x2.
    @return Pesos finais w1 e w2.
    """

    epoca = 1

    while True:

        erro_epoca = False

        print("\n" + "=" * 70)
        print(f"ÉPOCA {epoca}")
        print("=" * 70)

        print("Pesos iniciais da época:")
        print(f"w1 = {w1}")
        print(f"w2 = {w2}")
        print()

        # ----------------------------------------------------
        # Percorre os exemplos
        # ----------------------------------------------------
        for i, (x1, x2, d) in enumerate(dados, start=1):

            # ------------------------------------------------
            # Entrada líquida
            # ------------------------------------------------
            u = x1 * w1 + x2 * w2

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
                f"({x2} * {w2}) = {u}"
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

    return w1, w2


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

    # --------------------------------------------------------
    # Dados de treinamento da operação OR
    #
    # (x1, x2, saída desejada)
    # --------------------------------------------------------
    dados = [
        (0, 0, 0),
        (0, 1, 1),
        (1, 0, 1),
        (1, 1, 1)
    ]

    # --------------------------------------------------------
    # Inicia o treinamento
    # --------------------------------------------------------
    w1, w2 = treinar(
        dados,
        eta,
        w1,
        w2
    )

    # --------------------------------------------------------
    # Resultado final
    # --------------------------------------------------------
    print("\n" + "=" * 70)
    print("PESOS FINAIS")
    print("=" * 70)

    print(f"w1 = {w1}")
    print(f"w2 = {w2}")


# ------------------------------------------------------------
# EXECUÇÃO DO PROGRAMA
# ------------------------------------------------------------
if __name__ == "__main__":
    main()