class Construcao:
    def construir(self):
        self.preparar_terreno()
        self.construir_fundacao()
        self.levantar_estrutura()
        self.instalar_acabamentos()
        self.entregar_obra()

    def preparar_terreno(self):
        print("Limpando e nivelando o terreno.")

    def construir_fundacao(self):
        print("Construindo fundação padrão.")

    def levantar_estrutura(self):
        raise NotImplementedError

    def instalar_acabamentos(self):
        print("Instalando acabamentos padrão.")

    def entregar_obra(self):
        print("Obra concluída e entregue.")
