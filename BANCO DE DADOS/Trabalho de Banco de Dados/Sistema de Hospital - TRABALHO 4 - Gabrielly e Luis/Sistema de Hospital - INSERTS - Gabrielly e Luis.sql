-- ============================
-- INSERÇÕES
-- ============================

-- Tabela: Medicamento
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Paracetamol');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Ibuprofeno');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Amoxicilina');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Dipirona');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Omeprazol');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Cetorolaco');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Naproxeno');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Clonazepam');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Metformina');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Levotiroxina');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Dexametasona');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Hidroclorotiazida');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Propranolol');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Sertralina');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Warfarina');

-- Tabela: Doenca
INSERT INTO Doenca (nomeDoenca) VALUES ('Gripe');
INSERT INTO Doenca (nomeDoenca) VALUES ('Diabetes');
INSERT INTO Doenca (nomeDoenca) VALUES ('Hipertensão');
INSERT INTO Doenca (nomeDoenca) VALUES ('Asma');
INSERT INTO Doenca (nomeDoenca) VALUES ('Enxaqueca');
INSERT INTO Doenca (nomeDoenca) VALUES ('Artrite');
INSERT INTO Doenca (nomeDoenca) VALUES ('Câncer');
INSERT INTO Doenca (nomeDoenca) VALUES ('Doença Pulmonar Obstrutiva Crônica (DPOC)');
INSERT INTO Doenca (nomeDoenca) VALUES ('Acidente Vascular Cerebral (AVC)');
INSERT INTO Doenca (nomeDoenca) VALUES ('Infecção Urinária');

-- Tabela: Plano
INSERT INTO Plano (nomePlano) VALUES ('Unimed');
INSERT INTO Plano (nomePlano) VALUES ('Amil');
INSERT INTO Plano (nomePlano) VALUES ('Bradesco Saúde');
INSERT INTO Plano (nomePlano) VALUES ('SulAmérica');
INSERT INTO Plano (nomePlano) VALUES ('Hapvida');
INSERT INTO Plano (nomePlano) VALUES ('Intermédica');
INSERT INTO Plano (nomePlano) VALUES ('Porto Seguro');
INSERT INTO Plano (nomePlano) VALUES ('Bradesco Saúde Premium');
INSERT INTO Plano (nomePlano) VALUES ('Amil 400');
INSERT INTO Plano (nomePlano) VALUES ('Unimed Seguros');
INSERT INTO Plano (nomePlano) VALUES ('Plano Mega');

-- Tabela: Paciente
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('João da Silva', '123.456.789-00', '(27) 99999-0001');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Maria Oliveira', '987.654.321-00', '(27) 99999-0002');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Carlos Pereira', '111.222.333-44', '(27) 99999-0003');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Ana Costa', '555.666.777-88', '(27) 99999-0004');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Fernanda Lima', '999.888.777-66', '(27) 99999-0005');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Lucas Martins', '222.333.444-55', '(27) 99999-0006');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Tatiane Ferreira', '333.444.555-66', '(27) 99999-0007');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Roberto Santos', '444.555.666-77', '(27) 99999-0008');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Juliana Almeida', '555.666.777-88', '(27) 99999-0009');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Fernando Costa', '666.777.888-99', '(27) 99999-0010');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Paulo Rocha', '111.222.333-44', '(27) 99999-0011');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Lucia Santos', '222.333.444-55', '(27) 99999-0012');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Roberto Almeida', '333.444.555-66', '(27) 99999-0013');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Carla Pereira', '444.555.666-77', '(27) 99999-0014');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Marcos Lima', '555.666.777-88', '(27) 99999-0015');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Patricia Costa', '666.777.888-99', '(27) 99999-0016');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Gustavo Silva', '777.888.999-00', '(27) 99999-0017');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Daniela Oliveira', '888.999.000-11', '(27) 99999-0018');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Rafael Souza', '999.000.111-22', '(27) 99999-0019');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Tatiane Martins', '000.111.222-33', '(27) 99999-0020');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Eduardo Ferreira', '123.123.123-44', '(27) 99999-0021');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Amanda Rocha', '234.234.234-55', '(27) 99999-0022');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Bruno Santos', '345.345.345-66', '(27) 99999-0023');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Vanessa Almeida', '456.456.456-77', '(27) 99999-0024');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Diego Pereira', '567.567.567-88', '(27) 99999-0025');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Camila Lima', '678.678.678-99', '(27) 99999-0026');

-- Tabela: Medico
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Ricardo Alves', '12345678901');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Juliana Souza', '23456789012');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Marcos Paulo', '34567890123');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Laura Mendes', '45678901234');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Bruno Rocha', '56789012345');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Fernanda Rocha', '67890123456');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Felipe Almeida', '78901234567');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Simone Lima', '89012345678');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. André Santos', '90123456789');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Carla Mendes', '01234567890');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Marcelo Costa', 'CRM-SP 67890');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Renata Alves', 'CRM-SP 78901');

-- Tabela: Especialidade
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Clínico Geral');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Pediatria');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Cardiologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Endocrinologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Neurologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Geriatria');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Oftalmologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Dermatologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Psiquiatria');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Reumatologia');

-- Tabela: Consulta
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (1, 1, '2024-01-10');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (2, 2, '2024-02-15');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (3, 3, '2024-03-20');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (4, 4, '2024-04-01');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (5, 5, '2024-05-05');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (1, 6, '2024-01-15');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (2, 7, '2024-02-20');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (3, 8, '2024-03-25');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (4, 9, '2024-04-10');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (5, 10, '2024-05-15');

-- Tabela: Receita
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (1, 1, '500mg', '8 em 8h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (2, 2, '200mg', '6 em 6h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (3, 3, '250mg', '12 em 12h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (4, 4, '1g', '24 em 24h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (5, 5, '20mg', '1 vez ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (6, 6, '10mg', '1 vez ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (7, 7, '500mg', '2 vezes ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (8, 8, '1g', '1 vez ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (9, 9, '20mg', '1 vez ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (10, 10, '250mg', '3 vezes ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (2, 7, '50mg', '1x ao dia');

-- Tabela: Diagnostico
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (1, 1, 'Resfriado leve');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (2, 2, 'Diabetes tipo 2 controlada');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (3, 3, 'Pressão alta estável');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (4, 4, 'Asma leve');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (5, 5, 'Crise de enxaqueca');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (6, 1, 'Artrite reumatoide');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (7, 2, 'Câncer de mama em tratamento');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (8, 3, 'DPOC leve');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (9, 4, 'AVC isquêmico');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (10, 5, 'Infecção urinária aguda');

-- Tabela: Plano_Paciente
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 1);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (2, 2);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (3, 3);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (4, 4);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (5, 5);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 5);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 10);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 12);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 14);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 16);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 18);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 20);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 22);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 24);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 26);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 6);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (2, 7);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (3, 8);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (4, 9);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (5, 10);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 11);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 12);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 13);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 14);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 15);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 16);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 17);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 18);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 19);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 20);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 21);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 22);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 23);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 24);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 25);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (11, 26);

-- Tabela: Medico_Especialidade
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (1, 1);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (2, 2);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (3, 3);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (4, 4);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (5, 5);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (6, 1);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (7, 2);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (8, 3);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (9, 4);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (10, 5);
