import pandas as pd
import unicodedata
import os

# Lista de colunas que queremos manter
COLUNAS_DESEJADAS = [
    "ano",
    "data",
    "temp._ins._(c)",
    "temp._max._(c)",
    "temp._min._(c)",
    "temperatura_do_ar___bulbo_seco,_horaria_(c)",
    "temperatura_do_ponto_de_orvalho_(c)",
    "temperatura_maxima_na_hora_ant._(aut)_(c)",
    "temperatura_minima_na_hora_ant._(aut)_(c)",
    "temperatura_orvalho_max._na_hora_ant._(aut)_(c)",
    "temperatura_orvalho_min._na_hora_ant._(aut)_(c)",
    "consumidores",
    "consumo_kw"
]

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

def filtrar_colunas(csv_path: str, output_path: str = None) -> pd.DataFrame:
    """
    Carrega CSV, mantém apenas as colunas desejadas e salva em outro arquivo.
    """
    df = pd.read_csv(csv_path, encoding="utf-8")
    df = normalizar_colunas(df)

    # Manter apenas colunas que existem no CSV
    colunas_para_manter = [c for c in COLUNAS_DESEJADAS if c in df.columns]
    df_filtrado = df[colunas_para_manter]

    if output_path is None:
        base, ext = os.path.splitext(csv_path)
        output_path = f"{base}_filtrado{ext}"

    df_filtrado.to_csv(output_path, index=False, encoding="utf-8")
    print(f"[OK] CSV filtrado salvo em ../dados filtrados/{output_path} | Colunas mantidas: {len(colunas_para_manter)}")
    return df_filtrado

if __name__ == "__main__":
    # Exemplo de uso
    filtrar_colunas("./dados/anuario estatistico de energia eletrica.csv")
    filtrar_colunas("./dados/INMET_BRASILIA_01-01-2024_A_31-12-2024.csv")
    filtrar_colunas("./dados/INMP 15102025-15102025.csv")
