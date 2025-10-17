import pandas as pd
import unicodedata
import os

def normalizar_colunas(df: pd.DataFrame) -> pd.DataFrame:
    """
    Normaliza os nomes das colunas:
    - Remove acentos
    - Substitui espaços e caracteres especiais por "_"
    - Converte para minúsculas
    @param {pd.DataFrame} df - DataFrame de entrada.
    @return {pd.DataFrame} - DataFrame com colunas normalizadas.
    """
    df.columns = [
        unicodedata.normalize("NFKD", str(c))
        .encode("ascii", "ignore")
        .decode("ascii")
        .strip()
        .replace(" ", "_")
        .replace("/", "_")
        .replace("-", "_")
        .lower()
        for c in df.columns
    ]
    return df


def mesclar_csvs(*csv_paths, output_path="dados_unificados.csv", preencher_ausentes=False) -> pd.DataFrame:
    """
    Mescla múltiplos CSVs em um único DataFrame com base na coluna 'data'.

    @param {str[]} csv_paths - Caminhos dos arquivos CSV a unir.
    @param {str} output_path - Caminho do arquivo CSV de saída.
    @param {bool} preencher_ausentes - Se True, preenche valores ausentes com 0.
    @return {pd.DataFrame} - DataFrame final unificado.
    """
    if len(csv_paths) < 2:
        raise ValueError("Informe pelo menos dois arquivos CSV para mesclar.")

    dataframes = []
    print("[INICIANDO] Mesclagem de CSVs...\n")

    for path in csv_paths:
        if not os.path.exists(path):
            print(f"[ERRO] Arquivo não encontrado: {path}")
            continue

        try:
            df = pd.read_csv(path, encoding="utf-8")
        except UnicodeDecodeError:
            df = pd.read_csv(path, encoding="latin-1")

        df = normalizar_colunas(df)

        if "data" not in df.columns:
            print(f"[AVISO] '{os.path.basename(path)}' não possui coluna 'data'. Ignorado.")
            continue

        df["data"] = pd.to_datetime(df["data"], errors="coerce")
        df = df.dropna(subset=["data"])
        df["data"] = df["data"].dt.strftime("%Y-%m-%d")

        # Remove duplicadas por data no próprio arquivo
        df = df.drop_duplicates(subset=["data"], keep="first")

        print(f"[OK] {os.path.basename(path)} -> {len(df)} linhas | {len(df.columns)} colunas.")
        dataframes.append(df)

    if not dataframes:
        raise ValueError("Nenhum arquivo válido encontrado para mesclagem.")

    print("\n[PROCESSANDO] Unindo todos os CSVs por 'data'...")
    df_final = dataframes[0]

    for df in dataframes[1:]:
        df_final = pd.merge(df_final, df, on="data", how="outer")

    if preencher_ausentes:
        df_final = df_final.fillna(0)

    df_final = df_final.drop_duplicates(subset=["data"], keep="first")
    df_final = df_final.sort_values(by="data").reset_index(drop=True)

    df_final.to_csv(output_path, index=False, encoding="utf-8")

    print(f"\n[FINALIZADO] Arquivo unificado salvo em: {output_path}")
    print(f"[INFO] Linhas: {len(df_final)} | Colunas: {len(df_final.columns)}")

    return df_final


# =============================
# Exemplo de uso direto
# =============================
if __name__ == "__main__":
    df_final = mesclar_csvs(
        "./dados filtrados/anuario estatistico de energia eletrica_filtrado.csv",
        "./dados filtrados/INMET_BRASILIA_01-01-2024_A_31-12-2024_filtrado.csv",
        "./dados filtrados/INMP 15102025-15102025_filtrado.csv",
        output_path="dados_unificados.csv",
        preencher_ausentes=False,
    )
