import json
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
ARQUIVO_DADOS = BASE_DIR / "base_conhecimento.json"

BASE_INICIAL = [
    {"id": 1, "titulo": "Acesso VPN", "conteudo": "Usar Cisco AnyConnect...", "acessos": 120},
    {"id": 2, "titulo": "Backup SQL", "conteudo": "Scripts às 02h...", "acessos": 45},
    {"id": 3, "titulo": "Lentidão ERP", "conteudo": "Pausar Backup_Sync.", "acessos": 89}
]

def carregar_dados(caminho=ARQUIVO_DADOS):
    caminho = Path(caminho)
    if not caminho.exists():
        return [item.copy() for item in BASE_INICIAL]
    try:
        with caminho.open('r', encoding='utf-8') as f:
            dados = json.load(f)
            return dados if isinstance(dados, list) else []
    except (OSError, json.JSONDecodeError) as erro:
        print(f"Erro ao carregar os dados: {erro}")
        return []

def salvar_dados(base, caminho=ARQUIVO_DADOS):
    caminho = Path(caminho)
    caminho.parent.mkdir(parents=True, exist_ok=True)
    with caminho.open('w', encoding='utf-8') as f:
        json.dump(base, f, indent=4, ensure_ascii=False)
