# ============================================================
# RNSP-MPLN
# 2 nós, cada um com endereço de 3 bits
# Cada posição possui um contador de 0 a 4.
# Probabilidade = contador / 4
# Estado inicial = contador 2 -> p = 0,5
# ============================================================


class NoMPLN:

    def __init__(self, tamanho_endereco=3, N=4):
        self.tamanho = tamanho_endereco
        self.N = N

        # Todas as posições começam no estado neutro:
        # contador = 2 -> probabilidade 0,5
        self.memoria = [N // 2] * (2**tamanho_endereco)

    def treinar(self, endereco, classe):
        """
        Treinamento MPLN.

        Classe 1 -> incrementa o contador.
        Classe 0 -> decrementa o contador.

        O contador fica limitado entre 0 e N.
        """

        indice = int(endereco, 2)

        if classe == 1:
            self.memoria[indice] = min(self.memoria[indice] + 1, self.N)

        elif classe == 0:
            self.memoria[indice] = max(self.memoria[indice] - 1, 0)

    def probabilidade(self, endereco):
        """
        Retorna P(classe = 1).
        """

        indice = int(endereco, 2)

        return self.memoria[indice] / self.N

    def probabilidades(self, endereco):
        """
        Retorna P(0) e P(1).
        """

        p1 = self.probabilidade(endereco)
        p0 = 1 - p1

        return {"0": p0, "1": p1}

    def consultar(self, endereco):
        """
        Retorna o contador e as probabilidades
        da posição consultada.
        """

        indice = int(endereco, 2)

        contador = self.memoria[indice]
        p1 = contador / self.N
        p0 = 1 - p1

        return {"contador": contador, "p0": p0, "p1": p1}

    def mostrar_memoria(self):

        print("Endereço | Contador | P(0) | P(1)")
        print("-" * 35)

        for endereco, contador in enumerate(self.memoria):

            p1 = contador / self.N
            p0 = 1 - p1

            print(
                f"{endereco:03b}      | "
                f"{contador}        | "
                f"{p0:.2f} | "
                f"{p1:.2f}"
            )


# ============================================================
# DISCRIMINADOR MPLN
# ============================================================


class MPLN:

    def __init__(self):

        self.no_c = NoMPLN(3, 4)
        self.no_d = NoMPLN(3, 4)

    def treinar(self, padroes):

        for entrada, classe in padroes:

            endereco_c = entrada[:3]
            endereco_d = entrada[3:]

            self.no_c.treinar(endereco_c, classe)
            self.no_d.treinar(endereco_d, classe)

    def testar(self, entrada):

        # Divide a entrada em dois endereços
        endereco_c = entrada[:3]
        endereco_d = entrada[3:]

        # Consulta os dois nós
        resposta_c = self.no_c.consultar(endereco_c)
        resposta_d = self.no_d.consultar(endereco_d)

        # Probabilidades dos dois nós
        prob_c = self.no_c.probabilidades(endereco_c)
        prob_d = self.no_d.probabilidades(endereco_d)

        # Soma dos votos probabilísticos
        p0 = prob_c["0"] + prob_d["0"]
        p1 = prob_c["1"] + prob_d["1"]

        # Decisão
        if p1 > p0:
            classe = 1
        else:
            classe = 0

        return {
            "entrada": entrada,
            "endereco_c": endereco_c,
            "resposta_c": resposta_c,
            "prob_c": prob_c,
            "endereco_d": endereco_d,
            "resposta_d": resposta_d,
            "prob_d": prob_d,
            "soma_p0": p0,
            "soma_p1": p1,
            "classe": classe,
        }


# ============================================================
# DADOS DO EXERCÍCIO
# ============================================================

treinamento = [
    ("110011", 1),  # A1
    ("001100", 0),  # A2
    ("110101", 1),  # A3
    ("001011", 0),  # A4
    ("110011", 1),  # A5
    ("011100", 0),  # A6
]


# ============================================================
# TREINAMENTO
# ============================================================

mpln = MPLN()

mpln.treinar(treinamento)


# ============================================================
# MOSTRAR MEMÓRIA FINAL
# ============================================================

print("=" * 50)
print("MEMÓRIA FINAL DO NÓ C — MPLN")
print("=" * 50)

mpln.no_c.mostrar_memoria()


print("\n" + "=" * 50)
print("MEMÓRIA FINAL DO NÓ D — MPLN")
print("=" * 50)

mpln.no_d.mostrar_memoria()


# ============================================================
# TESTES
# ============================================================

testes = ["110101", "001111", "100011"]


print("\n" + "=" * 50)
print("TESTES — MPLN")
print("=" * 50)


for teste in testes:

    resultado = mpln.testar(teste)

    print("\nEntrada:", resultado["entrada"])

    print(
        "Nó C:"
        f" endereço={resultado['endereco_c']}"
        f" contador={resultado['resposta_c']['contador']}"
        f" P(0)={resultado['prob_c']['0']:.2f}"
        f" P(1)={resultado['prob_c']['1']:.2f}"
    )

    print(
        "Nó D:"
        f" endereço={resultado['endereco_d']}"
        f" contador={resultado['resposta_d']['contador']}"
        f" P(0)={resultado['prob_d']['0']:.2f}"
        f" P(1)={resultado['prob_d']['1']:.2f}"
    )

    print(f"Soma P(0) = {resultado['soma_p0']:.2f}")

    print(f"Soma P(1) = {resultado['soma_p1']:.2f}")

    print(f"Classe provável = {resultado['classe']}")
