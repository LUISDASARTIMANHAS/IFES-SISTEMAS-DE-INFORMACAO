import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LinearRegression
import statsmodels.api as sm


def load_and_prepare_csv(file_path: str) -> pd.DataFrame:
    """
    Lê o CSV, converte consumo e temperatura, e retorna um DataFrame limpo.
    """
    try:
        # Lê o CSV, com vírgula como separador decimal
        df = pd.read_csv(file_path, delimiter=",", decimal=",")
    except FileNotFoundError:
        print(f"[ERRO] Arquivo '{file_path}' não encontrado.")
        exit(1)

    # Renomeia a coluna de temperatura (se ela existir)
    temp_col = "temperatura_do_ar___bulbo_seco,_horaria_(c)"
    if temp_col in df.columns:
        df = df.rename(columns={temp_col: "temperatura_media"})
    else:
        print("[ERRO] Coluna de temperatura não encontrada no CSV.")
        exit(1)

    # Converte consumo para float (com tratamento de erro)
    df["consumo_kw"] = (
        df["consumo_kw"]
        .astype(str)
        .str.replace(",", ".", regex=False)
        .str.strip()
        .replace("", np.nan)
    )

    df["consumo_kw"] = pd.to_numeric(df["consumo_kw"], errors="coerce")

    # Seleciona apenas as colunas necessárias
    colunas_necessarias = ["data", "temperatura_media", "consumo_kw"]
    df = df[colunas_necessarias].copy()

    # Remove linhas com dados ausentes
    df = df.dropna()

    if df.empty:
        print("\n[ERRO] Nenhum dado válido encontrado após limpeza. Verifique o CSV.")
        exit(1)

    print("\n=== DADOS CARREGADOS ===")
    print(df)
    print(f"\nTotal de linhas válidas: {len(df)}")

    return df


def regressao_linear_simples(df: pd.DataFrame):
    """
    Aplica regressão linear simples: consumo ~ temperatura média.
    Gera gráfico e relatório.
    """
    X = df[["temperatura_media"]]
    y = df["consumo_kw"]

    # Ajuste com scikit-learn
    modelo = LinearRegression()
    modelo.fit(X, y)

    r2 = modelo.score(X, y)
    coef = modelo.coef_[0]
    intercept = modelo.intercept_

    # Ajuste com statsmodels para p-valor
    X_sm = sm.add_constant(X)
    modelo_sm = sm.OLS(y, X_sm).fit()

    print("\n=== RESULTADOS DA REGRESSÃO ===")
    print(modelo_sm.summary())

    # Gera gráfico
    sns.lmplot(
        x="temperatura_media",
        y="consumo_kw",
        data=df,
        ci=95,
        line_kws={"color": "red"}
    )
    plt.title("Relação entre Temperatura Média e Consumo de Energia")
    plt.xlabel("Temperatura Média (°C)")
    plt.ylabel("Consumo de Energia (kW)")
    plt.tight_layout()
    plt.savefig("grafico_regressao.png")
    print("\n[INFO] Gráfico salvo como: grafico_regressao.png")

    # Salva relatório
    with open("relatorio_regressao.txt", "w", encoding="utf-8") as f:
        f.write(modelo_sm.summary().as_text())

    print("[INFO] Relatório salvo como: relatorio_regressao.txt")


def main():
    arquivo_csv = "dados_unificados.csv"  # nome do arquivo com os dados
    df = load_and_prepare_csv(arquivo_csv)
    regressao_linear_simples(df)


if __name__ == "__main__":
    main()
