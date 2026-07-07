import tkinter as tk
from tkinter import messagebox, ttk

from colaboracao import criar_conhecimento
from dados import carregar_dados, salvar_dados
from logica import buscar_conhecimento


class InterfaceSGC:
    def __init__(self, root):
        self.root = root
        self.root.title("SGC - Gestão do Conhecimento")
        self.root.geometry("980x680")
        self.root.minsize(860, 560)

        self.base = carregar_dados()
        self.resultados = list(self.base)

        self.termo_busca = tk.StringVar()
        self.total_artigos = tk.StringVar()
        self.total_acessos = tk.StringVar()
        self.mais_acessado = tk.StringVar()
        self.status = tk.StringVar(value="Base carregada com sucesso.")

        self._configurar_estilo()
        self._montar_layout()
        self._atualizar_interface()

    def _configurar_estilo(self):
        estilo = ttk.Style(self.root)
        if "clam" in estilo.theme_names():
            estilo.theme_use("clam")

        estilo.configure("TFrame", background="#f4f7f9")
        estilo.configure("Header.TFrame", background="#0f3d3e")
        estilo.configure("Header.TLabel", background="#0f3d3e", foreground="#ffffff")
        estilo.configure("Title.TLabel", font=("Arial", 19, "bold"))
        estilo.configure("Subtitle.TLabel", font=("Arial", 10))
        estilo.configure("Metric.TLabel", background="#ffffff", font=("Arial", 18, "bold"))
        estilo.configure("MetricCaption.TLabel", background="#ffffff", foreground="#48616a")
        estilo.configure("TButton", padding=8)
        estilo.configure("Treeview", rowheight=28)
        estilo.configure("Treeview.Heading", font=("Arial", 10, "bold"))

    def _montar_layout(self):
        container = ttk.Frame(self.root, padding=14)
        container.pack(fill="both", expand=True)

        cabecalho = ttk.Frame(container, style="Header.TFrame", padding=18)
        cabecalho.pack(fill="x")

        texto_cabecalho = ttk.Frame(cabecalho, style="Header.TFrame")
        texto_cabecalho.pack(side="left", fill="x", expand=True)
        ttk.Label(
            texto_cabecalho,
            text="Sistema de Gestão do Conhecimento",
            style="Header.TLabel",
            font=("Arial", 20, "bold")
        ).pack(anchor="w")
        ttk.Label(
            texto_cabecalho,
            text="Busca, colaboração e análise de popularidade em uma única interface.",
            style="Header.TLabel",
            font=("Arial", 10)
        ).pack(anchor="w", pady=(4, 0))

        ttk.Button(cabecalho, text="Salvar agora", command=self._salvar).pack(side="right")

        abas = ttk.Notebook(container)
        abas.pack(fill="both", expand=True, pady=(14, 8))
        self.abas = abas

        self.aba_dashboard = ttk.Frame(abas, padding=14)
        self.aba_busca = ttk.Frame(abas, padding=14)
        self.aba_novo = ttk.Frame(abas, padding=14)
        abas.add(self.aba_dashboard, text="Dashboard")
        abas.add(self.aba_busca, text="Busca")
        abas.add(self.aba_novo, text="Novo conhecimento")

        self._montar_dashboard()
        self._montar_busca()
        self._montar_formulario()

        barra_status = ttk.Label(container, textvariable=self.status, anchor="w")
        barra_status.pack(fill="x")

    def _montar_dashboard(self):
        metricas = ttk.Frame(self.aba_dashboard)
        metricas.pack(fill="x", pady=(0, 14))
        metricas.columnconfigure((0, 1, 2), weight=1)

        self._criar_metrica(metricas, "Artigos", self.total_artigos, 0)
        self._criar_metrica(metricas, "Acessos registrados", self.total_acessos, 1)
        self._criar_metrica(metricas, "Mais utilizado", self.mais_acessado, 2)

        corpo = ttk.Frame(self.aba_dashboard)
        corpo.pack(fill="both", expand=True)
        corpo.columnconfigure(0, weight=3)
        corpo.columnconfigure(1, weight=2)
        corpo.rowconfigure(0, weight=1)

        grafico_area = ttk.Frame(corpo, padding=12)
        grafico_area.grid(row=0, column=0, sticky="nsew", padx=(0, 12))
        ttk.Label(
            grafico_area,
            text="Popularidade por acessos",
            style="Title.TLabel"
        ).pack(anchor="w")
        self.canvas_dashboard = tk.Canvas(
            grafico_area,
            background="#ffffff",
            highlightthickness=1,
            highlightbackground="#d8e1e5"
        )
        self.canvas_dashboard.pack(fill="both", expand=True, pady=(10, 0))
        self.canvas_dashboard.bind("<Configure>", lambda _evento: self._desenhar_dashboard())

        ranking_area = ttk.Frame(corpo, padding=12)
        ranking_area.grid(row=0, column=1, sticky="nsew")
        ttk.Label(ranking_area, text="Ranking", style="Title.TLabel").pack(anchor="w")
        self.ranking = ttk.Treeview(
            ranking_area,
            columns=("titulo", "acessos"),
            show="headings",
            height=12
        )
        self.ranking.heading("titulo", text="Título")
        self.ranking.heading("acessos", text="Acessos")
        self.ranking.column("titulo", width=220)
        self.ranking.column("acessos", width=80, anchor="center")
        self.ranking.pack(fill="both", expand=True, pady=(10, 0))

    def _criar_metrica(self, parent, legenda, variavel, coluna):
        card = tk.Frame(parent, background="#ffffff", highlightthickness=1, highlightbackground="#d8e1e5")
        card.grid(row=0, column=coluna, sticky="ew", padx=6)
        ttk.Label(card, text=legenda, style="MetricCaption.TLabel").pack(anchor="w", padx=14, pady=(12, 2))
        ttk.Label(card, textvariable=variavel, style="Metric.TLabel").pack(anchor="w", padx=14, pady=(0, 12))

    def _montar_busca(self):
        controles = ttk.Frame(self.aba_busca)
        controles.pack(fill="x")
        controles.columnconfigure(0, weight=1)

        campo = ttk.Entry(controles, textvariable=self.termo_busca, font=("Arial", 11))
        campo.grid(row=0, column=0, sticky="ew", padx=(0, 8))
        campo.bind("<Return>", lambda _evento: self._buscar())

        ttk.Button(controles, text="Buscar", command=self._buscar).grid(row=0, column=1, padx=(0, 8))
        ttk.Button(controles, text="Limpar", command=self._limpar_busca).grid(row=0, column=2)

        conteudo = ttk.Frame(self.aba_busca)
        conteudo.pack(fill="both", expand=True, pady=(14, 0))
        conteudo.columnconfigure(0, weight=3)
        conteudo.columnconfigure(1, weight=2)
        conteudo.rowconfigure(0, weight=1)

        lista_area = ttk.Frame(conteudo)
        lista_area.grid(row=0, column=0, sticky="nsew", padx=(0, 12))

        self.tabela = ttk.Treeview(
            lista_area,
            columns=("id", "titulo", "acessos"),
            show="headings"
        )
        self.tabela.heading("id", text="ID")
        self.tabela.heading("titulo", text="Título")
        self.tabela.heading("acessos", text="Acessos")
        self.tabela.column("id", width=50, anchor="center")
        self.tabela.column("titulo", width=360)
        self.tabela.column("acessos", width=90, anchor="center")
        self.tabela.pack(side="left", fill="both", expand=True)
        self.tabela.bind("<<TreeviewSelect>>", lambda _evento: self._mostrar_detalhes())

        rolagem = ttk.Scrollbar(lista_area, orient="vertical", command=self.tabela.yview)
        rolagem.pack(side="right", fill="y")
        self.tabela.configure(yscrollcommand=rolagem.set)

        detalhes_area = ttk.Frame(conteudo, padding=12)
        detalhes_area.grid(row=0, column=1, sticky="nsew")
        ttk.Label(detalhes_area, text="Detalhes", style="Title.TLabel").pack(anchor="w")
        self.detalhes = tk.Text(
            detalhes_area,
            height=12,
            wrap="word",
            font=("Arial", 10),
            background="#ffffff",
            relief="solid",
            borderwidth=1
        )
        self.detalhes.pack(fill="both", expand=True, pady=(10, 10))
        self.detalhes.configure(state="disabled")

        ttk.Button(
            detalhes_area,
            text="Registrar acesso no item selecionado",
            command=self._registrar_acesso
        ).pack(fill="x")

    def _montar_formulario(self):
        self.aba_novo.columnconfigure(0, weight=1)
        ttk.Label(self.aba_novo, text="Cadastrar novo conhecimento", style="Title.TLabel").grid(
            row=0,
            column=0,
            sticky="w"
        )

        ttk.Label(self.aba_novo, text="Título").grid(row=1, column=0, sticky="w", pady=(18, 4))
        self.campo_titulo = ttk.Entry(self.aba_novo, font=("Arial", 11))
        self.campo_titulo.grid(row=2, column=0, sticky="ew")

        ttk.Label(self.aba_novo, text="Conteúdo").grid(row=3, column=0, sticky="w", pady=(14, 4))
        self.campo_conteudo = tk.Text(
            self.aba_novo,
            height=9,
            wrap="word",
            font=("Arial", 10),
            background="#ffffff",
            relief="solid",
            borderwidth=1
        )
        self.campo_conteudo.grid(row=4, column=0, sticky="nsew")
        self.aba_novo.rowconfigure(4, weight=1)

        botoes = ttk.Frame(self.aba_novo)
        botoes.grid(row=5, column=0, sticky="e", pady=(14, 0))
        ttk.Button(botoes, text="Limpar", command=self._limpar_formulario).pack(side="left", padx=(0, 8))
        ttk.Button(botoes, text="Adicionar conhecimento", command=self._adicionar).pack(side="left")

    def _atualizar_interface(self):
        self._atualizar_metricas()
        self._preencher_tabela(self.resultados)
        self._preencher_ranking()
        self._desenhar_dashboard()

    def _atualizar_metricas(self):
        total_artigos = len(self.base)
        total_acessos = sum(int(item.get("acessos", 0)) for item in self.base)
        destaque = max(self.base, key=lambda item: int(item.get("acessos", 0)), default=None)

        self.total_artigos.set(str(total_artigos))
        self.total_acessos.set(str(total_acessos))
        self.mais_acessado.set(destaque["titulo"] if destaque else "-")

    def _preencher_tabela(self, itens):
        self.tabela.delete(*self.tabela.get_children())
        for item in itens:
            item_id = str(item.get("id"))
            self.tabela.insert(
                "",
                "end",
                iid=item_id,
                values=(item.get("id"), item.get("titulo"), item.get("acessos", 0))
            )
        self._mostrar_detalhes()

    def _preencher_ranking(self):
        self.ranking.delete(*self.ranking.get_children())
        ordenados = sorted(self.base, key=lambda item: int(item.get("acessos", 0)), reverse=True)
        for item in ordenados:
            self.ranking.insert("", "end", values=(item.get("titulo"), item.get("acessos", 0)))

    def _desenhar_dashboard(self):
        if not hasattr(self, "canvas_dashboard"):
            return

        canvas = self.canvas_dashboard
        canvas.delete("all")

        largura = max(canvas.winfo_width(), 520)
        altura = max(canvas.winfo_height(), 320)
        itens = sorted(self.base, key=lambda item: int(item.get("acessos", 0)), reverse=True)[:8]

        if not itens:
            canvas.create_text(largura / 2, altura / 2, text="Nenhum conhecimento cadastrado.", fill="#48616a")
            return

        margem_x = 150
        margem_y = 34
        espacamento = 34
        largura_barra = largura - margem_x - 46
        maior_acesso = max(int(item.get("acessos", 0)) for item in itens) or 1

        for indice, item in enumerate(itens):
            y = margem_y + indice * espacamento
            acessos = int(item.get("acessos", 0))
            tamanho = int((acessos / maior_acesso) * largura_barra)
            titulo = str(item.get("titulo", ""))[:24]

            canvas.create_text(16, y + 10, text=titulo, anchor="w", fill="#1d2b2f", font=("Arial", 10, "bold"))
            canvas.create_rectangle(margem_x, y, margem_x + largura_barra, y + 20, fill="#edf3f5", outline="")
            canvas.create_rectangle(margem_x, y, margem_x + tamanho, y + 20, fill="#2f7d80", outline="")
            canvas.create_text(
                margem_x + tamanho + 8,
                y + 10,
                text=str(acessos),
                anchor="w",
                fill="#1d2b2f",
                font=("Arial", 9)
            )

    def _buscar(self):
        termo = self.termo_busca.get()
        self.resultados = buscar_conhecimento(self.base, termo) if termo.strip() else list(self.base)
        self._preencher_tabela(self.resultados)
        self.status.set(f"{len(self.resultados)} resultado(s) encontrado(s).")

    def _limpar_busca(self):
        self.termo_busca.set("")
        self.resultados = list(self.base)
        self._preencher_tabela(self.resultados)
        self.status.set("Busca limpa.")

    def _mostrar_detalhes(self):
        selecionado = self._item_selecionado()
        self.detalhes.configure(state="normal")
        self.detalhes.delete("1.0", "end")

        if selecionado:
            texto = (
                f"ID: {selecionado.get('id')}\n"
                f"Título: {selecionado.get('titulo')}\n"
                f"Acessos: {selecionado.get('acessos', 0)}\n\n"
                f"{selecionado.get('conteudo')}"
            )
            self.detalhes.insert("1.0", texto)
        else:
            self.detalhes.insert("1.0", "Selecione um item para visualizar o conteúdo.")

        self.detalhes.configure(state="disabled")

    def _item_selecionado(self):
        selecao = self.tabela.selection()
        if not selecao:
            return None

        try:
            item_id = int(selecao[0])
        except ValueError:
            return None

        return next((item for item in self.base if item.get("id") == item_id), None)

    def _registrar_acesso(self):
        item = self._item_selecionado()
        if not item:
            messagebox.showwarning("Atenção", "Selecione um conhecimento antes de registrar acesso.")
            return

        item["acessos"] = int(item.get("acessos", 0)) + 1
        salvar_dados(self.base)
        self._buscar()
        self._atualizar_metricas()
        self._preencher_ranking()
        self._desenhar_dashboard()
        self.status.set(f"Acesso registrado para: {item.get('titulo')}.")

    def _adicionar(self):
        titulo = self.campo_titulo.get()
        conteudo = self.campo_conteudo.get("1.0", "end")

        try:
            novo = criar_conhecimento(self.base, titulo, conteudo)
        except ValueError as erro:
            messagebox.showerror("Dados obrigatórios", str(erro))
            return

        salvar_dados(self.base)
        self._limpar_formulario()
        self.resultados = list(self.base)
        self._atualizar_interface()
        self.abas.select(self.aba_busca)
        self.status.set(f"Conhecimento cadastrado: {novo['titulo']}.")

    def _limpar_formulario(self):
        self.campo_titulo.delete(0, "end")
        self.campo_conteudo.delete("1.0", "end")

    def _salvar(self):
        salvar_dados(self.base)
        self.status.set("Dados salvos em base_conhecimento.json.")


def main():
    root = tk.Tk()
    app = InterfaceSGC(root)
    root.mainloop()
    return app


if __name__ == "__main__":
    main()
