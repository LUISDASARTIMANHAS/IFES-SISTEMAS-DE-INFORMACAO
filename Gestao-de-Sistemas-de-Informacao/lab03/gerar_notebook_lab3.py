"""Gera o notebook de relatorio do Laboratorio 3."""

from __future__ import annotations

from pathlib import Path
from textwrap import dedent

import nbformat as nbf


BASE_DIR = Path(__file__).resolve().parent
NOTEBOOK_PATH = BASE_DIR / "Laboratorio_3_Lucas_Garcia_e_Luis_Augusto.ipynb"


def md(texto: str):
    return nbf.v4.new_markdown_cell(dedent(texto).strip())


def code(texto: str):
    return nbf.v4.new_code_cell(dedent(texto).strip())


def construir_notebook() -> nbf.NotebookNode:
    notebook = nbf.v4.new_notebook()
    notebook.metadata = {
        "kernelspec": {
            "display_name": "Python 3",
            "language": "python",
            "name": "python3",
        },
        "language_info": {"name": "python", "pygments_lexer": "ipython3"},
    }

    notebook.cells = [
        md(
            """
            # Laboratorio 3 - Integracao e Interoperabilidade de Sistemas

            **Relatorio para entrega em PDF/notebook**  
            Disciplina: Gestao de Sistemas de Informacao (GSI)  
            Alunos: Lucas Garcia e Luis Augusto  
            Tema: Middleware, ESB, API REST, interoperabilidade semantica e padronizacao ePING
            """
        ),
        md(
            """
            ## 1. Objetivo do laboratorio

            O laboratorio simula a integracao de sistemas legados heterogeneos,
            conhecidos como "ilhas de dados". A atividade mostra primeiro a
            falha de interoperabilidade causada por contratos de dados
            diferentes e, depois, implementa mecanismos para resolver o
            problema: um middleware/ESB, uma API REST padronizada, um tradutor
            semantico de unidades e um gateway de padronizacao inspirado na
            ePING.
            """
        ),
        md(
            """
            ## 2. Preparacao do ambiente

            Os scripts foram mantidos na pasta do laboratorio e importados pelo
            notebook para que a entrega funcione como relatorio e tambem como
            evidencia executavel. A API Flask nao precisa ficar rodando em
            background para a demonstracao: usaremos o `test_client()` do Flask
            para validar o contrato HTTP/JSON diretamente no notebook.
            """
        ),
        code(
            """
            from pathlib import Path
            import subprocess
            import sys

            import pandas as pd
            from IPython.display import Markdown, display

            POSSIVEIS_DIRS = [Path.cwd(), Path.cwd() / "GSI" / "lab3"]
            BASE_DIR = next(path for path in POSSIVEIS_DIRS if (path / "legacy_systems.py").exists())

            if str(BASE_DIR) not in sys.path:
                sys.path.insert(0, str(BASE_DIR))

            print(f"Diretorio do laboratorio: {BASE_DIR}")
            print("Arquivos principais:")
            for caminho in sorted(BASE_DIR.glob("*.py")):
                print(f"- {caminho.name}")
            """
        ),
        md(
            """
            ## 3. Parte 1 - O desafio da fragmentacao

            O Sistema de RH armazena o funcionario com os campos `id_func`,
            `nome_completo` e `salario_base`. O Sistema Financeiro, porem,
            espera receber `cod` e `valor`. Essa diferenca de contrato impede a
            integracao direta, mesmo que os dados representem a mesma entidade
            de negocio.
            """
        ),
        code(
            """
            from legacy_systems_original import (
                funcionario_rh as funcionario_rh_original,
                processar_pagamento as processar_pagamento_original,
            )

            print("Dados vindos do RH:")
            print(funcionario_rh_original)
            print()
            print("Tentativa de envio direto ao Financeiro:")
            processar_pagamento_original(funcionario_rh_original)
            """
        ),
        md(
            """
            A falha ocorre porque o Financeiro procura a chave `cod`, mas o RH
            envia `id_func`. Isso caracteriza uma falha de interoperabilidade
            tecnica e tambem semantica: os sistemas nao compartilham o mesmo
            contrato de dados.
            """
        ),
        md(
            """
            ## 4. Parte 2 - Middleware e barramento ESB

            Para resolver a incompatibilidade, foi implementado o
            `IntegradorESB`. Ele atua como uma camada intermediaria que traduz o
            contrato do RH para o contrato do Financeiro, preservando o
            significado dos dados.
            """
        ),
        code(
            """
            from integrador_esb import IntegradorESB
            from legacy_systems import funcionario_rh, processar_pagamento

            dados_convertidos = IntegradorESB.transformar_rh_para_financeiro(funcionario_rh)

            print("Dados originais do RH:")
            print(funcionario_rh)
            print()
            print("Dados convertidos pelo ESB:")
            print(dados_convertidos)
            print()
            print("Envio ao Financeiro apos conversao:")
            processar_pagamento(dados_convertidos)

            assert dados_convertidos == {"cod": 101, "valor": 5000.00}
            """
        ),
        md(
            """
            Com o ESB, a integracao deixa de depender de alteracoes diretas nos
            sistemas legados. O RH continua publicando seu formato original e o
            Financeiro continua consumindo o formato que espera, enquanto o
            middleware centraliza a transformacao.
            """
        ),
        md(
            """
            ## 5. Parte 3 - API REST e microservico ePING

            O roteiro tambem pede a simulacao de um microservico governamental
            seguindo um contrato padronizado. A implementacao usa Flask e expõe
            o endpoint `/api/cidadao/<id>`, retornando JSON com `cpf`, `nome` e
            `status`.
            """
        ),
        code(
            """
            from microservico_eping import app

            respostas = []
            with app.test_client() as client:
                for cidadao_id in [1, 2, 999]:
                    resposta = client.get(f"/api/cidadao/{cidadao_id}")
                    respostas.append({
                        "endpoint": f"/api/cidadao/{cidadao_id}",
                        "status_http": resposta.status_code,
                        "json": resposta.get_json(),
                    })

            pd.DataFrame(respostas)
            """
        ),
        md(
            """
            O uso de HTTP e JSON resolve a interoperabilidade tecnica. O
            contrato do JSON, com campos padronizados, apoia a
            interoperabilidade semantica, pois consumidores diferentes passam a
            interpretar os dados da mesma forma.
            """
        ),
        md(
            """
            ## 6. Parte 4 - Interoperabilidade semantica

            No desafio de temperatura, enviar apenas o numero `100` e omitir a
            unidade pode gerar erro grave de interpretacao: `100 C` e `100 F`
            significam coisas diferentes. A funcao `tradutor_universal()`
            padroniza o dado para Celsius antes do envio ao Sistema de Saude.
            """
        ),
        code(
            """
            from interop_semantica import enviar_para_sistema_saude, tradutor_universal

            cenarios = [(37, "C"), (100, "F")]
            resultados = []

            for valor, unidade in cenarios:
                valor_convertido, unidade_convertida = tradutor_universal(valor, unidade)
                enviar_para_sistema_saude(valor_convertido, unidade_convertida)
                resultados.append({
                    "valor_original": valor,
                    "unidade_original": unidade,
                    "valor_enviado": round(valor_convertido, 2),
                    "unidade_enviada": unidade_convertida,
                })

            assert resultados[0]["valor_enviado"] == 37
            assert resultados[1]["valor_enviado"] == 37.78

            pd.DataFrame(resultados)
            """
        ),
        md(
            """
            **Reflexao:** apenas transmitir o numero sem a unidade fere a
            interoperabilidade semantica porque o receptor recebe sintaxe, mas
            nao recebe significado. A unidade faz parte do contrato do dado.
            Sem ela, dois sistemas podem aceitar a mensagem e ainda assim tomar
            decisoes erradas.
            """
        ),
        md(
            """
            ## 7. Parte 5 - Governanca e padronizacao ePING

            O ultimo desafio simula a integracao entre orgaos publicos. O
            Ministerio da Fazenda envia CPF com mascara e nome em formato livre,
            enquanto o sistema consumidor exige CPF numerico e nome em
            maiusculas. A funcao `normalizar_cadastro()` atua como gateway de
            integracao.
            """
        ),
        code(
            """
            from padronizacao_eping import normalizar_cadastro

            cadastros_origem = [
                {"cpf": "123.456.789-00", "nome": "Eduardo Amaral"},
                {"cpf": "987.654.321-00", "nome": "Maria Silva"},
            ]

            cadastros_normalizados = [
                normalizar_cadastro(cadastro) for cadastro in cadastros_origem
            ]

            assert cadastros_normalizados[0] == {
                "cpf": "12345678900",
                "nome": "EDUARDO AMARAL",
                "origem_validada": True,
            }

            pd.DataFrame(cadastros_normalizados)
            """
        ),
        md(
            """
            **Reflexao:** se o formato do CPF mudar, a atualizacao deve ser
            concentrada no middleware/gateway de integracao sempre que possivel.
            Essa decisao reduz acoplamento, evita alteracoes duplicadas nos
            ministerios consumidores e torna a arquitetura mais resiliente a
            mudancas de contrato.
            """
        ),
        md(
            """
            ## 8. Codigo-fonte desenvolvido

            Para deixar a entrega autocontida, os principais scripts do
            laboratorio sao exibidos abaixo em formato textual.
            """
        ),
        code(
            """
            def mostrar_codigo_fonte(nome_arquivo: str) -> None:
                caminho = BASE_DIR / nome_arquivo
                codigo = caminho.read_text(encoding="utf-8")
                display(Markdown(f"### Codigo-fonte: `{nome_arquivo}`"))
                display(Markdown(f"```python\\n{codigo}\\n```"))


            for arquivo in [
                "legacy_systems_original.py",
                "legacy_systems.py",
                "integrador_esb.py",
                "microservico_eping.py",
                "interop_semantica.py",
                "padronizacao_eping.py",
            ]:
                mostrar_codigo_fonte(arquivo)
            """
        ),
        md(
            """
            ## 9. Evidencias de execucao dos scripts

            As proximas execucoes registram as saidas dos scripts principais.
            O microservico Flask foi validado na Parte 3 por meio de
            `test_client()`, evitando iniciar um servidor permanente durante a
            geracao do relatorio.
            """
        ),
        code(
            """
            def executar_script(nome_arquivo: str) -> None:
                resultado = subprocess.run(
                    [sys.executable, str(BASE_DIR / nome_arquivo)],
                    capture_output=True,
                    text=True,
                    check=False,
                )
                print("=" * 70)
                print(f"$ python {nome_arquivo}")
                print("=" * 70)
                print(resultado.stdout)
                if resultado.stderr:
                    print("STDERR:")
                    print(resultado.stderr)
                print(f"Codigo de retorno: {resultado.returncode}")


            for script in [
                "legacy_systems_original.py",
                "legacy_systems.py",
                "interop_semantica.py",
                "padronizacao_eping.py",
            ]:
                executar_script(script)
            """
        ),
        md(
            """
            ## 10. Conclusao

            O laboratorio demonstra que interoperabilidade nao e apenas conectar
            sistemas. A integracao direta falha quando os contratos de dados sao
            diferentes. O ESB resolve a transformacao entre sistemas legados; a
            API REST cria um contrato tecnico padronizado; o tradutor de
            unidades preserva o significado dos dados; e o gateway de
            padronizacao centraliza regras organizacionais. Em conjunto, essas
            solucoes reduzem acoplamento, aumentam governanca e tornam a
            arquitetura mais preparada para mudancas.
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
