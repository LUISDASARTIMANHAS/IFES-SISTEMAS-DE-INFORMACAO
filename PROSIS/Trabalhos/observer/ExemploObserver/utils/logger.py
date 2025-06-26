# utils/logger.py
from observer import Observer

class Logger(Observer):
    def update(self, data):
        print(f"[Logger] Novo dado recebido: {data}")
