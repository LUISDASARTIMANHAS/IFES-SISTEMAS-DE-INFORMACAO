# Protótipo RNSP-PLN
# 2 nós, cada um com endereço de 3 bits

class NoPLN:
    def __init__(self, tamanho_endereco=3):
        self.tamanho = tamanho_endereco
        self.memoria = ["u"] * (2 ** tamanho_endereco)

        # Guarda as ocorrências para podermos calcular
        # as probabilidades quando houver conflito.
        self.ocorrencias = [
            [] for _ in range(2 ** tamanho_endereco)
        ]

    def treinar(self, endereco, classe):
        """
        endereco: string de bits, ex.: '110'
        classe: 0 ou 1
        """
        indice = int(endereco, 2)
        self.ocorrencias[indice].append(classe)

        classes = self.ocorrencias[indice]

        if all(c == 0 for c in classes):
            self.memoria[indice] = 0

        elif all(c == 1 for c in classes):
            self.memoria[indice] = 1

        else:
            self.memoria[indice] = "u"

    def consultar(self, endereco):
        """
        Retorna o conteúdo da posição de memória.
        """
        indice = int(endereco, 2)
        return self.memoria[indice]

    def probabilidades(self, endereco):
        """
        Retorna P(0) e P(1) para o endereço consultado.
        """
        indice = int(endereco, 2)
        ocorrencias = self.ocorrencias[indice]

        if not ocorrencias:
            return {"0": 0.5, "1": 0.5}

        total = len(ocorrencias)
        p0 = ocorrencias.count(0) / total
        p1 = ocorrencias.count(1) / total

        return {"0": p0, "1": p1}

    def mostrar_memoria(self):
        for endereco, valor in enumerate(self.memoria):
            print(f"{endereco:03b} -> {valor}")


class PLN:
    def __init__(self):
        self.no_c = NoPLN(3)
        self.no_d = NoPLN(3)

    def treinar(self, padroes):
        for entrada, classe in padroes:
            endereco_c = entrada[:3]
            endereco_d = entrada[3:]

            self.no_c.treinar(endereco_c, classe)
            self.no_d.treinar(endereco_d, classe)

    def testar(self, entrada):
        endereco_c = entrada[:3]
        endereco_d = entrada[3:]

        resposta_c = self.no_c.consultar(endereco_c)
        resposta_d = self.no_d.consultar(endereco_d)

        prob_c = self.no_c.probabilidades(endereco_c)
        prob_d = self.no_d.probabilidades(endereco_d)

        # Soma das probabilidades dos dois nós
        p0 = prob_c["0"] + prob_d["0"]
        p1 = prob_c["1"] + prob_d["1"]

        classe = 1 if p1 > p0 else 0

        return {
            "entrada": entrada,
            "endereco_c": endereco_c,
            "resposta_c": resposta_c,
            "prob_c": prob_c,
            "endereco_d": endereco_d,
            "resposta_d": resposta_d,
            "prob_d": prob_d,
            "classe": classe
        }


# ============================================
# DADOS DO EXERCÍCIO
# ============================================

treinamento = [
    ("110011", 1),  # A1
    ("001100", 0),  # A2
    ("110101", 1),  # A3
    ("001011", 0),  # A4
    ("110011", 1),  # A5
    ("011100", 0),  # A6
]


# ============================================
# TREINAMENTO
# ============================================

pln = PLN()
pln.treinar(treinamento)


# ============================================
# MOSTRAR MEMÓRIAS
# ============================================

print("MEMÓRIA DO NÓ C")
print("-" * 20)
pln.no_c.mostrar_memoria()

print("\nMEMÓRIA DO NÓ D")
print("-" * 20)
pln.no_d.mostrar_memoria()


# ============================================
# TESTES
# ============================================

testes = [
    "110101",
    "001111",
    "100011",
]

print("\nTESTES")
print("=" * 50)

for teste in testes:
    resultado = pln.testar(teste)

    print(f"\nEntrada: {resultado['entrada']}")

    print(
        f"Nó C: endereço={resultado['endereco_c']} "
        f"resposta={resultado['resposta_c']} "
        f"probabilidades={resultado['prob_c']}"
    )

    print(
        f"Nó D: endereço={resultado['endereco_d']} "
        f"resposta={resultado['resposta_d']} "
        f"probabilidades={resultado['prob_d']}"
    )

    print(f"Classe provável: {resultado['classe']}")
