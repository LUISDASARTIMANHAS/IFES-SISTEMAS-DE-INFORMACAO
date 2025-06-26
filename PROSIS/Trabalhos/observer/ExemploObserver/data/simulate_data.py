# data/simulate_data.py
import random
import threading
import time

def simular_dados(sensor):
    def loop():
        while True:
            novo_valor = random.randint(10, 90)
            sensor.set_data(novo_valor)
            time.sleep(2)
    threading.Thread(target=loop, daemon=True).start()
