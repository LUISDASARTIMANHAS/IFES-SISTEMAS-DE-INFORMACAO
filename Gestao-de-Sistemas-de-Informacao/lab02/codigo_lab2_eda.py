# codigo_lab2_eda.py

print("\n==============================")
print("SIMULAÇÃO 1 — ARQUITETURA ACOPLADA")
print("==============================")

# --- ARQUITETURA ACOPLADA ---

def sensor_cardiaco_acoplado():
    return {"bpm": 180}

def luva_acoplada():
    dados = sensor_cardiaco_acoplado()  # Luva conhece diretamente o sensor
    if dados["bpm"] > 160:
        print("Luva recebeu BPM diretamente do sensor.")
        print("AÇÃO: Parando luva.")
        return "PARADA"
    return "OK"

status = luva_acoplada()
print(f"Status final: {status}")

print("\n⚠ Problema: Se o sensor mudar, a luva precisa ser alterada.\n")


# =============================================================

print("\n==============================")
print("SIMULAÇÃO 2 — ARQUITETURA EDA (DESACOPLADA)")
print("==============================")

# --- BARRAMENTO DE EVENTOS ---
event_bus = []

def publicar_evento(tipo, dados):
    event_bus.append({"tipo": tipo, "dados": dados})
    print(f"Evento publicado: {tipo}")

def sensor_cardiaco_eda():
    print("Sensor cardíaco detectou BPM crítico.")
    publicar_evento("ALERTA_CARDIACO", {"bpm": 180})

def luva_consumer_eda():
    print("Luva escutando eventos...")
    for evento in event_bus:
        if evento["tipo"] == "ALERTA_CARDIACO":
            print("Evento cardíaco recebido pela luva.")
            print("AÇÃO: Parando luva.")
            return "PARADA"
    return "OK"

# Fluxo EDA
sensor_cardiaco_eda()  # Sensor publica
status = luva_consumer_eda()  # Luva apenas escuta

print(f"Status final: {status}")

print("\n✅ Vantagem: A luva não conhece o sensor cardíaco.")
print("Ela apenas reage a eventos publicados.")