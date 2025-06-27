# main.py
import tkinter as tk
from data.simulate_data import simular_dados
from utils.logger import Logger
from gui.dashboard import GraphWidget, TextWidget, StatusWidget, BarWidget


class SensorData:
    def __init__(self):
        from subject import Subject
        self._subject = Subject()
        self._valor = 0

    def attach(self, observer):
        self._subject.attach(observer)

    def detach(self, observer):
        self._subject.detach(observer)

    def notify(self):
        self._subject.notify(self._valor)

    def set_data(self, valor):
        self._valor = valor
        print(f"[Sensor] Novo valor: {valor}")
        self.notify()

# Interface principal
def main():
    sensor = SensorData()
    root = tk.Tk()
    root.title("Dashboard Observer")

    dashboard_frame = tk.Frame(root)
    dashboard_frame.pack()

    graph = GraphWidget(dashboard_frame)
    bar = BarWidget(dashboard_frame)
    text = TextWidget(dashboard_frame)
    status = StatusWidget(dashboard_frame)

    sensor.attach(graph)
    sensor.attach(bar)
    sensor.attach(text)
    sensor.attach(status)

    # logger também pode ser adicionado aqui se quiser
    # logger = Logger()
    # sensor.attach(logger)

    simular_dados(sensor)
    root.mainloop()

if __name__ == "__main__":
    main()


