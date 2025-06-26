# gui/dashboard.py
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
from observer import Observer

# 🔹 1. Gráfico de histórico
class GraphWidget(Observer):
    def __init__(self, parent):
        self.data = []
        self.frame = tk.LabelFrame(parent, text="Histórico (Graph)", padx=10, pady=10)
        self.frame.grid(row=0, column=0, padx=10, pady=10)

        self.fig = Figure(figsize=(4, 2), dpi=100)
        self.ax = self.fig.add_subplot(111)
        self.ax.set_ylim(0, 100)
        self.line, = self.ax.plot([], [], color="green")

        self.canvas = FigureCanvasTkAgg(self.fig, master=self.frame)
        self.canvas.get_tk_widget().pack()

    def update(self, value):
        self.data.append(value)
        if len(self.data) > 20:
            self.data.pop(0)
        self.line.set_data(range(len(self.data)), self.data)
        self.ax.set_xlim(0, max(20, len(self.data)))
        self.ax.set_ylim(0, max(100, max(self.data) + 10))
        self.canvas.draw()


# 🔹 2. Barra vertical
class BarWidget(Observer):
    def __init__(self, parent):
        self.frame = tk.LabelFrame(parent, text="Barra Atual", padx=10, pady=10)
        self.frame.grid(row=0, column=1, padx=10, pady=10)

        self.canvas = tk.Canvas(self.frame, width=100, height=150, bg="white")
        self.canvas.pack()
        self.rect = self.canvas.create_rectangle(30, 150, 70, 150, fill="blue")

    def update(self, value):
        altura = max(10, min(140, value))
        self.canvas.coords(self.rect, 30, 150 - altura, 70, 150)


# 🔹 3. Texto do valor atual
class TextWidget(Observer):
    def __init__(self, parent):
        self.frame = tk.LabelFrame(parent, text="Valor Atual", padx=10, pady=10)
        self.frame.grid(row=1, column=0, padx=10, pady=10)
        self.label = tk.Label(self.frame, text="--", font=("Arial", 20))
        self.label.pack()

    def update(self, value):
        self.label.config(text=f"{value}")


# 🔹 4. Indicador de status com emoji
class StatusWidget(Observer):
    def __init__(self, parent):
        self.frame = tk.LabelFrame(parent, text="Status", padx=10, pady=10)
        self.frame.grid(row=1, column=1, padx=10, pady=10)
        self.label = tk.Label(self.frame, text="---", width=15, font=("Arial", 14), bg="gray")
        self.label.pack()

    def update(self, value):
        if value < 30:
            self.label.config(text="❄️ Baixo", bg="lightblue")
        elif value < 70:
            self.label.config(text="🌤️ Médio", bg="lightyellow")
        else:
            self.label.config(text="🔥 Alto", bg="lightcoral")
