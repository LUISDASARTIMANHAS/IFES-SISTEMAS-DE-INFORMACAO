import pandas as pd
import unicodedata
import os

def normalizar_colunas(df: pd.DataFrame) -> pd.DataFrame:
    """
    Normaliza os nomes das colunas:
    - Remove acentos
    - Substitui espaços e caracteres especiais por "_"
    - Converte para minúsculas
    """
    df.columns = [
        unicodedata.normalize('NFKD', str(c))
        .encode('ascii', 'ignore')
        .decode('ascii')
        .strip()
        .replace(" ", "_")
        .replace("/", "_")
        .replace("-", "_")
        .lower()
        for c in df.columns
    ]
    return df

def mesclar_csvs(*csv_paths, output_path="dados_unificados.csv", preencher_ausentes=False, limite_linhas=None):
    """
    Mescla múltiplos CSVs em um único arquivo unificado.
    
    @param {str[]} csv_paths - Caminhos dos arquivos CSV.
    @param {str} output_path - Nome do arquivo de saída.
    @param {bool} preencher_ausentes - Se True, preenche valores ausentes com 0.
    @param {int | None} limite_linhas - Se definido, exporta apenas até este número de linhas.
    @return {pd.DataFrame} - DataFrame final.
    """
    if len(csv_paths) < 2:
        raise ValueError("Informe pelo menos dois arquivos CSV para mesclar.")

    dataframes = []
    print("[INICIANDO] Mesclagem de CSVs...\n")

    for path in csv_paths:
        if not os.path.exists(path):
            print(f"[ERRO] Arquivo não encontrado: {path}")
            continue

        df = pd.read_csv(path, encoding="utf-8")
        df = normalizar_colunas(df)
        print(f"[OK] {os.path.basename(path)} carregado com {len(df)} linhas e {len(df.columns)} colunas.")
        dataframes.append(df)

    print("\n[PROCESSANDO] Unindo todos os CSVs...")
    df_final = pd.concat(dataframes, ignore_index=True, sort=False)

    # Limitar o número de linhas, se solicitado
    if limite_linhas is not None and len(df_final) > limite_linhas:
        print(f"[INFO] Reduzindo o dataset para {limite_linhas} linhas...")
        df_final = df_final.sample(n=limite_linhas, random_state=42)  # amostragem aleatória

    if preencher_ausentes:
        df_final = df_final.fillna(0)

    df_final.to_csv(output_path, index=False, encoding="utf-8")
    print(f"\n[FINALIZADO] Arquivo unificado salvo em: {output_path}")
    print(f"[INFO] Total exportado: {len(df_final)} linhas, {len(df_final.columns)} colunas")

    return df_final


# =============================
# Exemplo de uso
# =============================
if __name__ == "__main__":
    df_final = mesclar_csvs(
        "anuario estatistico de energia eletrica_filtrado.csv",
        "INMET_BRASILIA_01-01-2024_A_31-12-2024_filtrado.csv",
        "INMP 15102025-15102025_filtrado.csv",
        output_path="dados_unificados_10k.csv",
        preencher_ausentes=False,
        limite_linhas=10000  # <<<<< define o limite aqui
    )
