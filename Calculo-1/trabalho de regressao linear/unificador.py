import pandas as pd
import unicodedata
import os

def normalizar_colunas(df: pd.DataFrame) -> pd.DataFrame:
    """
    Normaliza os nomes das colunas:
    - Remove acentos
    - Converte espaços e caracteres especiais para "_"
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

def mesclar_csvs(*csv_paths, output_path="dados_unificados.csv", preencher_ausentes=False):
    """
    Mescla múltiplos CSVs em um único DataFrame unificado.
    
    @param {str[]} csv_paths - Caminhos dos arquivos CSV a unir.
    @param {str} output_path - Nome do arquivo de saída.
    @param {bool} preencher_ausentes - Se True, preenche valores ausentes com 0.
    @return {pd.DataFrame} - DataFrame final unificado.
    """
    if len(csv_paths) < 2:
        raise ValueError("Você deve informar pelo menos dois arquivos CSV para mesclar.")

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

    # Faz o merge completo com todas as colunas existentes
    print("\n[PROCESSANDO] Unindo todos os CSVs...")
    df_final = pd.concat(dataframes, ignore_index=True, sort=False)

    # Preencher valores ausentes, se ativado
    if preencher_ausentes:
        df_final = df_final.fillna(0)

    # Salva o resultado final
    df_final.to_csv(output_path, index=False, encoding="utf-8")
    print(f"\n[FINALIZADO] Arquivo unificado salvo em: {output_path}")
    print(f"[INFO] Total de linhas: {len(df_final)}, colunas: {len(df_final.columns)}")

    return df_final

# =============================
# Exemplo de uso direto:
# =============================
if __name__ == "__main__":
    df_final = mesclar_csvs(
        "anuario estatistico de energia eletrica_filtrado.csv",
        "INMET_BRASILIA_01-01-2024_A_31-12-2024_filtrado.csv",
        "INMP 15102025-15102025_filtrado.csv",
        output_path="dados_unificados.csv",
        preencher_ausentes=True
    )
