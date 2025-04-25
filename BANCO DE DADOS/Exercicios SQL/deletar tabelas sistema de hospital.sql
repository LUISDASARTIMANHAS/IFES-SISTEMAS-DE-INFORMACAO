DELETE FROM Receita
WHERE
    idConsulta = 5
    AND idMedicamento = 5;

DELETE FROM Diagnostico
WHERE
    idConsulta = 5
    AND idDoenca = 5;

DELETE FROM Plano_Paciente
WHERE
    idPlano = 5
    AND idPaciente = 5;

DELETE FROM Medico_Especialidade
WHERE
    idMedico = 5
    AND idEspecialidade = 5;

DELETE FROM Consulta
WHERE
    idConsulta = 5;

DELETE FROM Medico
WHERE
    idMedico = 5;

DELETE FROM Paciente
WHERE
    idPaciente = 5;

DELETE FROM Medicamento
WHERE
    idMedicamento = 5;

DELETE FROM Doenca
WHERE
    idDoenca = 5;

DELETE FROM Plano
WHERE
    idPlano = 5;

DELETE FROM Especialidade
WHERE
    idEspecialidade = 5;