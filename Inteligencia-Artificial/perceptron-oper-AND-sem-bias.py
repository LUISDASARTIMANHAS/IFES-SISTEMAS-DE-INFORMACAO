# ============================================================
# PERCEPTRON - OPERAÇÃO AND - SEM BIAS
# ============================================================


# ------------------------------------------------------------
# 1. FUNÇÃO DE ATIVAÇÃO
# ------------------------------------------------------------
def ativacao(u):
    """
    Função de ativação do Perceptron sem bias.

    Se u > 0, retorna 1.
    Caso contrário, retorna 0.

    @param u Entrada líquida.
    @return Saída binária do Perceptron.
    """
    if u > 0:
        return 1

    return 0


# ------------------------------------------------------------
# 2. CÁLCULO DO ERRO
# ------------------------------------------------------------
def calcular_erro(d, y):
    """
    Calcula o erro do Perceptron.

    e = d - y

    @param d Saída desejada.
    @param y Saída produzida.
    @return Erro calculado.
    """
    return d - y


# ------------------------------------------------------------
# 3. ATUALIZAÇÃO DOS PESOS
# ------------------------------------------------------------
def atualizar_pesos(w1, w2, eta, e, x1, x2):
    """
    Atualiza os pesos do Perceptron.

    w1 = w1 + eta * e * x1
    w2 = w2 + eta * e * x2

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
# 4. TREINAMENTO
# ------------------------------------------------------------
def treinar(dados, eta, w1, w2):
    """
    Treina o Perceptron até uma época completa sem erros.

    @param dados Dados de treinamento.
    @param eta Taxa de aprendizagem.
    @param w1 Peso inicial da entrada x1.
    @param w2 Peso inicial da entrada x2.
    @return Pesos finais.
    """

    epoca = 1

    while True:

        erro_epoca = False

        print("\n" + "=" * 70)
        print(f"ÉPOCA {epoca}")
        print("=" * 70)

        print(f"w1 = {w1}")
        print(f"w2 = {w2}")
        print()

        for i, (x1, x2, d) in enumerate(dados, start=1):

            # ------------------------------------------------
            # Entrada líquida
            # ------------------------------------------------
            u = x1 * w1 + x2 * w2

            # ------------------------------------------------
            # Saída
            # ------------------------------------------------
            y = ativacao(u)

            # ------------------------------------------------
            # Erro
            # ------------------------------------------------
            e = calcular_erro(d, y)

            print(f"Exemplo {i}")
            print(f"x1 = {x1}, x2 = {x2}, desejado = {d}")

            print(
                f"U = ({x1} * {w1}) + "
                f"({x2} * {w2}) = {u}"
            )

            print(f"y = {y}")
            print(f"e = {d} - {y} = {e}")

            # ------------------------------------------------
            # Atualização
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
        # Verificação
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

    # Taxa de aprendizagem
    eta = 1

    # Pesos iniciais
    w1 = 0
    w2 = 0

    # Dados da operação AND
    dados = [
        (0, 0, 0),
        (0, 1, 0),
        (1, 0, 0),
        (1, 1, 1)
    ]

    # Treinamento
    w1, w2 = treinar(
        dados,
        eta,
        w1,
        w2
    )

    # Resultado
    print("\n" + "=" * 70)
    print("PESOS FINAIS")
    print("=" * 70)

    print(f"w1 = {w1}")
    print(f"w2 = {w2}")


# ------------------------------------------------------------
# EXECUÇÃO
# ------------------------------------------------------------
if __name__ == "__main__":
    main()