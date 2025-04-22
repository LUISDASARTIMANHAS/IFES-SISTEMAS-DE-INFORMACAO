UPDATE Medicamento
SET
    nomeMedicamento = 'Paracetamol Xarope'
WHERE
    idMedicamento = 1;

UPDATE Doenca
SET
    nomeDoenca = 'Influenza'
WHERE
    idDoenca = 1;

UPDATE Plano
SET
    nomePlano = 'Unimed Nacional'
WHERE
    idPlano = 1;

UPDATE Paciente
SET
    telefone = '(27) 98888-0000'
WHERE
    idPaciente = 1;

UPDATE Medico
SET
    nomeMedico = 'Dr. Ricardo A. Lima'
WHERE
    idMedico = 1;

UPDATE Especialidade
SET
    nomeEspecialidade = 'Clínica Geral'
WHERE
    idEspecialidade = 1;

UPDATE Consulta
SET
    dataConsulta = '2024-01-11'
WHERE
    idConsulta = 1;

UPDATE Receita
SET
    intervaloDose = '6 em 6h'
WHERE
    idConsulta = 1
    AND idMedicamento = 1;

UPDATE Diagnostico
SET
    descricao = 'Sintomas de gripe comum'
WHERE
    idConsulta = 1
    AND idDoenca = 1;

UPDATE Plano_Paciente
SET
    idPlano = 2
WHERE
    idPlano = 1
    AND idPaciente = 1;

UPDATE Medico_Especialidade
SET
    idEspecialidade = 2
WHERE
    idMedico = 1
    AND idEspecialidade = 1;