import pandas as pd
import unicodedata
import os
import numpy as np

def normalizar_colunas(df: pd.DataFrame) -> pd.DataFrame:
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
    if len(csv_paths) < 2:
        raise ValueError("Informe pelo menos dois arquivos CSV para mesclar.")

    dataframes = []

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

        colunas_temperatura = [c for c in df.columns if "temp" in c]
        colunas_consumo = [c for c in df.columns if "consumo" in c and "kw" in c]

        for c in colunas_temperatura + colunas_consumo:
            df[c] = pd.to_numeric(df[c], errors="coerce")

        df["temperatura_media"] = df[colunas_temperatura].mean(axis=1, skipna=True) if colunas_temperatura else np.nan
        df["consumo_kw"] = df[colunas_consumo].mean(axis=1, skipna=True) if colunas_consumo else np.nan

        df = df[["data", "consumo_kw", "temperatura_media"]]

        df = df.groupby("data", as_index=False).mean(numeric_only=True)
        dataframes.append(df)

    if not dataframes:
        raise ValueError("Nenhum arquivo válido encontrado.")

    df_final = pd.concat(dataframes, ignore_index=True)
    df_final = df_final.groupby("data", as_index=False).mean(numeric_only=True)

    # Preencher ausentes com média mensal
    df_final["mes"] = df_final["data"].dt.month
    for col in ["consumo_kw", "temperatura_media"]:
        df_final[col] = df_final.groupby("mes")[col].transform(lambda x: x.fillna(x.mean()))
    df_final = df_final.drop(columns=["mes"])

    df_final = df_final.sort_values(by="data").reset_index(drop=True)
    df_final.to_csv(output_path, index=False, encoding="utf-8")

    print(f"[FINALIZADO] Arquivo unificado salvo em: {output_path}")
    print(f"[INFO] Linhas: {len(df_final)} | Colunas: {len(df_final.columns)}")
    return df_final

if __name__ == "__main__":
    df_final = mesclar_csvs(
        "./dados filtrados/anuario estatistico de energia eletrica_filtrado.csv",
        "./dados filtrados/INMET_BRASILIA_01-01-2024_A_31-12-2024_filtrado.csv",
        "./dados filtrados/INMP 15102025-15102025_filtrado.csv",
        output_path="dados_unificados.csv",
        preencher_ausentes=False,
    )
