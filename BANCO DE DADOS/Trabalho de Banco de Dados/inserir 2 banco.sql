

-- Inserindo mais receitas
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (6, 6, '10mg', '1 vez ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (7, 7, '500mg', '2 vezes ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (8, 8, '1g', '1 vez ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (9, 9, '20mg', '1 vez ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (10, 10, '250mg', '3 vezes ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (11, 1, '500mg', '8/8 horas');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (12, 2, '400mg', '12/12 horas');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (13, 3, '500mg', '8/8 horas');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (14, 4, '500mg', '6/6 horas');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (15, 5, '20mg', '1x ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (16, 6, '10mg', '1x ao dia');
INSERT INTO Receita (idConsulta, idMedicamento, dose, intervaloDose) VALUES (17, 7, '50mg', '1x ao dia');


-- Inserindo mais associações de planos e pacientes
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


-- Inserindo mais associações de médicos e especialidades
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (6, 1);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (7, 2);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (8, 3);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (9, 4);
INSERT INTO Medico_Especialidade (idMedico, idEspecialidade) VALUES (10, 5);
