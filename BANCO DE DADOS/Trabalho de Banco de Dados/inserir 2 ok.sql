-- Inserindo mais medicamentos
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


-- Inserindo mais doenças
INSERT INTO Doenca (nomeDoenca) VALUES ('Artrite');
INSERT INTO Doenca (nomeDoenca) VALUES ('Câncer');
INSERT INTO Doenca (nomeDoenca) VALUES ('Doença Pulmonar Obstrutiva Crônica (DPOC)');
INSERT INTO Doenca (nomeDoenca) VALUES ('Acidente Vascular Cerebral (AVC)');
INSERT INTO Doenca (nomeDoenca) VALUES ('Infecção Urinária');


-- Inserindo mais planos de saúde
INSERT INTO Plano (nomePlano) VALUES ('Intermédica');
INSERT INTO Plano (nomePlano) VALUES ('Porto Seguro');
INSERT INTO Plano (nomePlano) VALUES ('Bradesco Saúde Premium');
INSERT INTO Plano (nomePlano) VALUES ('Amil 400');
INSERT INTO Plano (nomePlano) VALUES ('Unimed Seguros');
INSERT INTO Plano (nomePlano) VALUES ('Plano Mega');


-- Inserindo mais pacientes
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


-- Inserindo mais médicos
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Fernanda Rocha', '67890123456');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Felipe Almeida', '78901234567');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Simone Lima', '89012345678');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. André Santos', '90123456789');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Carla Mendes', '01234567890');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dr. Marcelo Costa', 'CRM-SP 67890');
INSERT INTO Medico (nomeMedico, CRM) VALUES ('Dra. Renata Alves', 'CRM-SP 78901');


-- Inserindo mais especialidades
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Geriatria');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Oftalmologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Dermatologia');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Psiquiatria');
INSERT INTO Especialidade (nomeEspecialidade) VALUES ('Reumatologia');


-- Inserindo mais consultas
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (1, 6, '2024-01-15');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (2, 7, '2024-02-20');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (3, 8, '2024-03-25');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (4, 9, '2024-04-10');
INSERT INTO Consulta (idMedico, idPaciente, dataConsulta) VALUES (5, 10, '2024-05-15');


-- Inserindo mais diagnósticos
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (6, 1, 'Artrite reumatoide');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (7, 2, 'Câncer de mama em tratamento');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (8, 3, 'DPOC leve');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (9, 4, 'AVC isquêmico');
INSERT INTO Diagnostico (idConsulta, idDoenca, descricao) VALUES (10, 5, 'Infecção urinária aguda');