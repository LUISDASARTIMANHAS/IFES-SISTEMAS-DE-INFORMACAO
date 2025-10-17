import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
import numpy as np
import os

# === 1. Carregar o CSV ===
df = pd.read_csv("dados_unificados.csv")  # substitua pelo nome do seu arquivo

# Seleciona apenas as colunas necessárias
df = df[["consumo_kw", "temperatura_media"]].dropna()

# === 2. Preparar os dados ===
X = df["temperatura_media"].values.reshape(-1, 1)  # variável independente
y = df["consumo_kw"].values  # variável dependente

# === 3. Criar e treinar o modelo de regressão linear ===
model = LinearRegression()
model.fit(X, y)

# === 4. Previsões para a linha de regressão ===
y_pred = model.predict(X)

# === 5. Calcular R² ===
r2 = r2_score(y, y_pred)
r = np.sqrt(r2) * np.sign(model.coef_[0])  # R com sinal do coeficiente

# === 6. Criar diretório para salvar gráficos ===
os.makedirs("./graficos", exist_ok=True)

# === 7. Plotar os dados e a linha de regressão ===
plt.figure(figsize=(10, 6))
plt.scatter(X, y, color='blue', label="Dados reais")
plt.plot(X, y_pred, color='red', linewidth=2, label="Regressão Linear")
plt.xlabel("Temperatura Média (°C)")
plt.ylabel("Consumo (kW)")
plt.title("Regressão Linear: Consumo x Temperatura Média")
plt.legend()
plt.grid(True)

# Adicionar R no gráfico
plt.text(
    0.05, 0.95, f"R = {r:.3f}", 
    transform=plt.gca().transAxes, 
    fontsize=12, 
    verticalalignment='top',
    bbox=dict(boxstyle="round,pad=0.3", facecolor="white", edgecolor="black")
)

# === 8. Salvar o gráfico no diretório ./graficos ===
plt.savefig("./graficos/regressao_consumo_temperatura.png", dpi=300)
plt.show()

# === 9. Coeficientes da regressão ===
print(f"Coeficiente angular (slope): {model.coef_[0]}")
print(f"Intercepto: {model.intercept_}")
print(f"R²: {r2}")
print(f"R: {r}")
