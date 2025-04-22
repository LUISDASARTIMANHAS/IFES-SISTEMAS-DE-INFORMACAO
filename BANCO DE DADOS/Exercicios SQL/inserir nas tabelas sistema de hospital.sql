-- Tabela: Medicamento
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Paracetamol');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Ibuprofeno');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Amoxicilina');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Dipirona');
INSERT INTO Medicamento (nomeMedicamento) VALUES ('Omeprazol');

-- Tabela: Doenca
INSERT INTO Doenca (nomeDoenca) VALUES ('Gripe');
INSERT INTO Doenca (nomeDoenca) VALUES ('Diabetes');
INSERT INTO Doenca (nomeDoenca) VALUES ('Hipertensão');
INSERT INTO Doenca (nomeDoenca) VALUES ('Asma');
INSERT INTO Doenca (nomeDoenca) VALUES ('Enxaqueca');

-- Tabela: Plano
INSERT INTO Plano (nomePlano) VALUES ('Unimed');
INSERT INTO Plano (nomePlano) VALUES ('Amil');
INSERT INTO Plano (nomePlano) VALUES ('Bradesco Saúde');
INSERT INTO Plano (nomePlano) VALUES ('SulAmérica');
INSERT INTO Plano (nomePlano) VALUES ('Hapvida');

-- Tabela: Paciente
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('João da Silva', '123.456.789-00', '(27) 99999-0001');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Maria Oliveira', '987.654.321-00', '(27) 99999-0002');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Carlos Pereira', '111.222.333-44', '(27) 99999-0003');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Ana Costa', '555.666.777-88', '(27) 99999-0004');
INSERT INTO Paciente (nomePaciente, CPF, telefone) VALUES ('Fernanda Lima', '999.888.777-66', '(27) 99999-0005');

-- Tabela: Medico
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Ricardo Alves', '12345678901');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Juliana Souza', '23456789012');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Marcos Paulo', '34567890123');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Laura Mendes', '45678901234');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Bruno Rocha', '56789012345');

-- Tabela: Especialidade
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Clínico Geral');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Pediatria');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Cardiologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Endocrinologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Neurologia');

-- Tabela: Consulta
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (1, 1, '2024-01-10');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (2, 2, '2024-02-15');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (3, 3, '2024-03-20');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (4, 4, '2024-04-01');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (5, 5, '2024-05-05');

-- Tabela: Receita
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (1, 1, '500mg', '8 em 8h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (2, 2, '200mg', '6 em 6h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (3, 3, '250mg', '12 em 12h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (4, 4, '1g', '24 em 24h');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (5, 5, '20mg', '1 vez ao dia');

-- Tabela: Diagnostico
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (1, 1, 'Resfriado leve');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (2, 2, 'Diabetes tipo 2 controlada');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (3, 3, 'Pressão alta estável');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (4, 4, 'Asma leve');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (5, 5, 'Crise de enxaqueca');

-- Tabela: Plano_Paciente
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (1, 1);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (2, 2);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (3, 3);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (4, 4);
INSERT INTO Plano_Paciente (idPlano, idPaciente) VALUES (5, 5);

-- Tabela: Medico_Especialidade
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (1, 1);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (2, 2);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (3, 3);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (4, 4);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (5, 5);
