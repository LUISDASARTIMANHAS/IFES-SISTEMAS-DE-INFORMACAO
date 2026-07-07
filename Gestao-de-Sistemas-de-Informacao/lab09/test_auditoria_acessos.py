"""Testes do Laboratorio 9 - Auditoria avancada de seguranca e acesso."""

from __future__ import annotations

import sys
import unittest
from pathlib import Path

import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
if str(BASE_DIR) not in sys.path:
    sys.path.insert(0, str(BASE_DIR))

from auditoria_acessos import (
    ARQUIVO_LOGS,
    ARQUIVO_RH,
    carregar_base_rh,
    carregar_logs,
    classificar_acessos_sucesso,
    cruzar_bases,
    gerar_analise_critica,
    gerar_sugestao_controle,
    identificar_acessos_autorizados,
    identificar_contas_orfas,
    identificar_fora_horario,
    identificar_ips_externos_sucesso,
    identificar_usuarios_inativos_ou_bloqueados,
    montar_resumo_classificacao,
    montar_resumo_incidentes,
)


class AuditoriaAcessosTestCase(unittest.TestCase):
    """Valida as regras centrais do laboratorio 9."""

    @staticmethod
    def carregar_base_real() -> pd.DataFrame:
        logs = carregar_logs(Path(ARQUIVO_LOGS))
        rh = carregar_base_rh(Path(ARQUIVO_RH))
        return cruzar_bases(logs, rh)

    def test_contagens_da_base_real(self) -> None:
        cruzado = self.carregar_base_real()

        self.assertEqual(len(cruzado), 200)
        self.assertEqual(len(identificar_contas_orfas(cruzado)), 200)
        self.assertEqual(len(identificar_usuarios_inativos_ou_bloqueados(cruzado)), 0)
        self.assertEqual(len(identificar_fora_horario(cruzado)), 106)
        self.assertEqual(len(identificar_ips_externos_sucesso(cruzado)), 72)
        self.assertEqual(len(identificar_acessos_autorizados(cruzado)), 0)

    def test_classificacao_controlada(self) -> None:
        logs = pd.DataFrame(
            [
                {
                    "id_acesso": 1,
                    "usuario": "ana",
                    "data_hora": "2023-11-01 09:00:00",
                    "ip_origem": "192.168.1.10",
                    "status": "Sucesso",
                },
                {
                    "id_acesso": 2,
                    "usuario": "ana",
                    "data_hora": "2023-11-01 19:00:00",
                    "ip_origem": "192.168.1.20",
                    "status": "Sucesso",
                },
                {
                    "id_acesso": 3,
                    "usuario": "bruno",
                    "data_hora": "2023-11-01 10:00:00",
                    "ip_origem": "45.10.10.10",
                    "status": "Sucesso",
                },
                {
                    "id_acesso": 4,
                    "usuario": "carla",
                    "data_hora": "2023-11-01 11:00:00",
                    "ip_origem": "192.168.1.30",
                    "status": "Falha",
                },
            ]
        )
        logs["data_hora"] = pd.to_datetime(logs["data_hora"])

        rh = pd.DataFrame(
            [
                {"usuario": "ana", "departamento": "TI", "status_contrato": "Ativo"},
                {"usuario": "carla", "departamento": "RH", "status_contrato": "Inativo"},
            ]
        )

        cruzado = cruzar_bases(logs, rh)
        classificacao = classificar_acessos_sucesso(cruzado)
        resumo = montar_resumo_classificacao(cruzado)

        self.assertEqual(identificar_contas_orfas(cruzado)["id_acesso"].tolist(), [3])
        self.assertEqual(
            identificar_usuarios_inativos_ou_bloqueados(cruzado)["id_acesso"].tolist(),
            [4],
        )
        self.assertEqual(identificar_fora_horario(cruzado)["id_acesso"].tolist(), [2])
        self.assertEqual(
            identificar_ips_externos_sucesso(cruzado)["id_acesso"].tolist(), [3]
        )
        self.assertEqual(
            classificacao["classificacao"].tolist(),
            [
                "Acessos Autorizados",
                "Violacoes de Horario",
                "Usuarios Inexistentes/Inativos",
            ],
        )
        self.assertEqual(resumo["quantidade"].tolist(), [1, 1, 1])

    def test_resumos_e_textos_da_base_real(self) -> None:
        cruzado = self.carregar_base_real()
        resumo_classificacao = montar_resumo_classificacao(cruzado)
        resumo_incidentes = montar_resumo_incidentes(cruzado)
        analise = gerar_analise_critica(cruzado)
        sugestao = gerar_sugestao_controle(cruzado)

        self.assertEqual(
            resumo_classificacao["categoria"].tolist(),
            [
                "Acessos Autorizados",
                "Violacoes de Horario",
                "Usuarios Inexistentes/Inativos",
            ],
        )
        self.assertEqual(resumo_classificacao["quantidade"].tolist(), [0, 0, 161])
        self.assertEqual(
            resumo_incidentes["quantidade"].tolist(),
            [200, 0, 106, 72, 0],
        )
        self.assertIn("offboarding", analise.lower())
        self.assertIn("161", analise)
        self.assertIn("dashboard de BI".lower(), sugestao.lower())
        self.assertIn("200", sugestao)


if __name__ == "__main__":
    unittest.main()
