# Importação das bibliotecas necessárias
import functions
# Lista com amostras de PGs para testar diferentes comportamentos
amostras = [
    (2, 0.5),   # PG convergente com razão menor que 1
    (1, 0.9),   # PG convergente com razão menor que 1
    (3, -0.5),  # PG convergente, mas com termos alternando entre positivo e negativo
    (5, 1),     # PG constante (não converge), r == 1
    (1, -1),    # PG divergente, os termos oscilam entre 1 e -1
    (1, 1.5)    # PG divergente, com termos crescendo sem limites
]


# Loop principal que executa todos os cálculos para cada PG
for a, r in amostras:
    t_lim = functions.limite_termo(a, r)           # Calcula o limite do termo geral
    S_lim = functions.limite_soma(a, r)            # Calcula o limite da soma infinita, se ela existir
    termos = functions.termos_pg(a, r)             # Gera os primeiros termos da PG
    somas = functions.somas_parciais(termos)       # Calcula as somas parciais dos primeiros n termos
    converg, aprox = functions.testar_convergencia(a, r)   # Testa se a PG converge e retorna o valor do termo aproximado


    # Exibe os resultados no console
    print("------------------------------------------------------------")
    print(f"a={a}, r={r}")  # Imprime os valores de a e r da PG
    print(f"Limite do termo: {t_lim}")  # Imprime o limite do termo geral
    print(f"Limite da soma infinita: {S_lim}")  # Imprime o limite da soma infinita (se existir)
    print(f"Converge: {converg}, último termo: {aprox}")  # Exibe se a PG converge e o valor aproximado do último termo


    # Gera e salva os gráficos dos termos e das somas parciais
    functions.plot_termos(a, r, termos)  # Plota e salva o gráfico dos termos
    functions.plot_somas(a, r, somas)    # Plota e salva o gráfico das somas parciais


# Mensagem final indicando que o código terminou de executar
print("Pronto.")
