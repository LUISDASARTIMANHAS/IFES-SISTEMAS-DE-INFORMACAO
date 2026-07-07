"""Gera o notebook de relatorio do Laboratorio 9."""

from __future__ import annotations

from pathlib import Path
from textwrap import dedent

import nbformat as nbf


BASE_DIR = Path(__file__).resolve().parent
NOTEBOOK_PATH = BASE_DIR / "Laboratorio_9_Lucas_Garcia_e_Luis_Augusto.ipynb"


def md(texto: str):
    return nbf.v4.new_markdown_cell(dedent(texto).strip())


def code(texto: str):
    return nbf.v4.new_code_cell(dedent(texto).strip())


def construir_notebook() -> nbf.NotebookNode:
    notebook = nbf.v4.new_notebook()
    notebook.cells = [
        md(
            """
            # Laboratorio 9 - Auditoria Avancada de Seguranca e Acesso

            **Relatorio para entrega em PDF**  
            Disciplina: Gestao de Sistemas de Informacao (GSI)  
            Alunos: Lucas Garcia e Luis Augusto  
            Prazo informado: 14/05
            """
        ),
        md(
            """
            ## 1. Objetivo do laboratorio

            Auditar os logs de autenticacao do sistema core da TechStore S.A.
            cruzando os acessos com a base de RH para localizar contas orfas,
            acessos fora do horario comercial e logins bem-sucedidos vindos de
            IPs externos. O notebook tambem registra evidencias de execucao,
            exibe o dashboard visual e responde aos itens analiticos do roteiro.
            """
        ),
        md(
            """
            ## 2. Preparacao do ambiente

            O roteiro pede `pandas`, `matplotlib` e `datetime`. Para manter o
            codigo-fonte textual e reutilizavel, o notebook importa as rotinas
            do script principal `auditoria_acessos.py`.
            """
        ),
        code(
            """
            from pathlib import Path
            import subprocess
            import sys

            import pandas as pd
            from IPython.display import Image, Markdown, display

            POSSIVEIS_DIRS = [Path.cwd(), Path.cwd() / "GSI" / "lab9"]
            BASE_DIR = next(path for path in POSSIVEIS_DIRS if (path / "log_acessos_200_registros.csv").exists())
            if str(BASE_DIR) not in sys.path:
                sys.path.insert(0, str(BASE_DIR))

            from auditoria_acessos import (
                ARQUIVO_LOGS,
                ARQUIVO_RH,
                carregar_base_rh,
                carregar_logs,
                classificar_acessos_sucesso,
                cruzar_bases,
                executar_auditoria,
                gerar_analise_critica,
                gerar_sugestao_controle,
                identificar_contas_orfas,
                identificar_fora_horario,
                identificar_ips_externos_sucesso,
                identificar_usuarios_inativos_ou_bloqueados,
                montar_ranking_usuarios_risco,
                montar_resumo_classificacao,
                montar_resumo_incidentes,
            )

            LOG_PATH = BASE_DIR / "log_acessos_200_registros.csv"
            RH_PATH = BASE_DIR / "usuarios_ativos_200_registros.csv"
            OUT_DIR = BASE_DIR / "saidas"
            LOG_PATH, RH_PATH
            """
        ),
        md(
            """
            ## 3. Carga e entendimento das bases

            Primeiro carregamos os dois CSVs, convertemos `data_hora` para
            `datetime` e aplicamos o `merge` com `how='left'`, como pedido no
            roteiro. Esse cruzamento preserva todos os acessos do log e apenas
            agrega os dados do RH quando o usuario existe na base corporativa.
            """
        ),
        code(
            """
            logs = carregar_logs(LOG_PATH)
            rh = carregar_base_rh(RH_PATH)
            cruzado = cruzar_bases(logs, rh)

            print(f"Total de acessos no log: {len(logs)}")
            print(f"Total de usuarios na base do RH: {len(rh)}")
            print(f"Usuarios distintos no log: {logs['usuario'].nunique()}")
            print(f"Usuarios distintos no RH: {rh['usuario'].nunique()}")
            print()
            cruzado.head(10)
            """
        ),
        md(
            """
            A base de RH usa identificadores no formato `user001`, `user002`,
            enquanto o log traz usuarios como `lucas_ti`, `paulo_fin` e
            `tiago_suporte`. Essa diferenca de padrao ja sugere um problema de
            governanca entre o cadastro de identidades e a trilha de acesso.
            """
        ),
        code(
            """
            print("Usuarios unicos presentes no log:")
            print(sorted(logs["usuario"].unique()))
            print()
            print("Primeiros usuarios do RH:")
            print(rh["usuario"].head(15).tolist())
            """
        ),
        md(
            """
            ## 4. Tarefa 1 - Cruzamento de dados e contas orfas

            Contas orfas sao acessos de usuarios que nao possuem correspondencia
            valida na base do RH. Esse eh o achado mais critico do laboratorio,
            porque indica falha no ciclo de vida de identidades.
            """
        ),
        code(
            """
            contas_orfas = identificar_contas_orfas(cruzado)
            usuarios_inativos = identificar_usuarios_inativos_ou_bloqueados(cruzado)

            print(f"Acessos sem correspondencia no RH: {len(contas_orfas)}")
            print(f"Acessos de usuarios existentes porem nao ativos: {len(usuarios_inativos)}")
            display(contas_orfas.head(10))
            """
        ),
        md(
            """
            ## 5. Tarefa 2 - Auditoria de horario comercial

            O horario permitido vai de 08:00 ate antes de 18:00. A celula abaixo
            usa a hora extraida de `data_hora` para filtrar os acessos fora desse
            intervalo.
            """
        ),
        code(
            """
            fora_horario = identificar_fora_horario(cruzado)

            print(f"Acessos fora do horario comercial: {len(fora_horario)}")
            print(f"Acessos com sucesso fora do horario: {len(fora_horario[fora_horario['status'] == 'Sucesso'])}")
            display(fora_horario.head(10))
            """
        ),
        md(
            """
            ## 6. Tarefa 3 - Identificacao de IPs externos

            O roteiro pede a filtragem de acessos de sucesso cujo IP nao comeca
            com `192.168`, simulando acessos externos nao autorizados pela VPN.
            """
        ),
        code(
            """
            ips_externos_sucesso = identificar_ips_externos_sucesso(cruzado)

            print(f"Acessos com sucesso vindos de IP externo: {len(ips_externos_sucesso)}")
            display(ips_externos_sucesso.head(10))
            """
        ),
        md(
            """
            ## 7. Tarefa 4 - Dashboard visual de riscos

            Para que o grafico de pizza seja coerente, os acessos com sucesso sao
            classificados de forma exclusiva em tres grupos:

            1. `Acessos Autorizados`: usuario ativo no RH e dentro do horario.
            2. `Violacoes de Horario`: usuario ativo no RH, mas fora do horario.
            3. `Usuarios Inexistentes/Inativos`: usuario ausente no RH ou sem status ativo.

            Como complemento, o dashboard tambem traz um grafico de barras com os
            contadores absolutos dos principais incidentes.
            """
        ),
        code(
            """
            resultado = executar_auditoria(LOG_PATH, RH_PATH, OUT_DIR)
            resumo_classificacao = resultado["resumo_classificacao"]
            resumo_incidentes = resultado["resumo_incidentes"]

            display(resumo_classificacao)
            display(resumo_incidentes)
            print(f"Dashboard salvo em: {resultado['dashboard']}")
            Image(filename=str(resultado["dashboard"]))
            """
        ),
        md(
            """
            ## 8. Analise complementar

            Alem do resumo geral, vale priorizar usuarios com maior volume de
            acessos bem-sucedidos fora do horario e a partir de IPs externos.
            """
        ),
        code(
            """
            ranking_riscos = montar_ranking_usuarios_risco(cruzado)
            ranking_riscos.head(10)
            """
        ),
        md(
            """
            Nesta base, o cruzamento revela um problema estrutural: nenhum dos
            15 usuarios do log aparece na base do RH. Como consequencia, os 161
            acessos com sucesso ficam classificados como `Usuarios Inexistentes/Inativos`,
            e nao existe nenhum acesso plenamente autorizado.
            """
        ),
        md(
            """
            ## 9. Codigo-fonte desenvolvido

            O professor pediu que o codigo apareca de forma textual no arquivo
            final. As celulas abaixo carregam os scripts usados nesta entrega.
            """
        ),
        code(
            """
            def mostrar_codigo_fonte(nome_arquivo: str) -> None:
                caminho = BASE_DIR / nome_arquivo
                codigo = caminho.read_text(encoding="utf-8")
                display(Markdown(f"### Codigo-fonte: `{nome_arquivo}`"))
                display(Markdown(f"```python\\n{codigo}\\n```"))

            for arquivo in ["auditoria_acessos.py", "test_auditoria_acessos.py"]:
                mostrar_codigo_fonte(arquivo)
            """
        ),
        md(
            """
            ## 10. Evidencias de execucao

            As proximas celulas executam o script principal e a bateria de
            testes. A saida fica incorporada ao notebook e pode ser mantida no
            PDF final como evidencia objetiva da execucao.
            """
        ),
        code(
            """
            comando_script = [sys.executable, str(BASE_DIR / "auditoria_acessos.py")]
            resultado_script = subprocess.run(comando_script, capture_output=True, text=True, check=True)
            print(resultado_script.stdout)
            if resultado_script.stderr:
                print(resultado_script.stderr)
            """
        ),
        code(
            """
            comando_testes = [sys.executable, "-m", "unittest", "-v", str(BASE_DIR / "test_auditoria_acessos.py")]
            resultado_testes = subprocess.run(comando_testes, capture_output=True, text=True, check=True)
            print(resultado_testes.stdout)
            if resultado_testes.stderr:
                print(resultado_testes.stderr)
            """
        ),
        md(
            """
            ## 11. Analise critica pedida no roteiro

            Pergunta: "A presenca de acessos com sucesso de usuarios fora da base
            do RH indica qual falha especifica na Gestao de Identidade e Acesso (IAM)?"
            """
        ),
        code(
            """
            print(gerar_analise_critica(cruzado))
            """
        ),
        md(
            """
            ## 12. Sugestao de controle baseada em BI

            Pergunta: "Baseado no conceito de BI, como um dashboard em tempo real
            poderia mitigar esses riscos?"
            """
        ),
        code(
            """
            print(gerar_sugestao_controle(cruzado))
            """
        ),
        md(
            """
            ## 13. Conclusao

            O laboratorio 9 foi concluido com os itens exigidos no roteiro:
            cruzamento entre logs e RH, deteccao de contas orfas, filtro de
            acessos fora do horario comercial, identificacao de IPs externos com
            sucesso, dashboard visual de riscos, scripts em formato textual e
            evidencias de execucao. Para entrega, este notebook pode ser exportado
            diretamente para HTML ou PDF preservando o codigo, as tabelas e os
            graficos.
            """
        ),
    ]
    return notebook


def main() -> None:
    notebook = construir_notebook()
    nbf.write(notebook, NOTEBOOK_PATH)
    print(f"Notebook gerado em: {NOTEBOOK_PATH}")


if __name__ == "__main__":
    main()
