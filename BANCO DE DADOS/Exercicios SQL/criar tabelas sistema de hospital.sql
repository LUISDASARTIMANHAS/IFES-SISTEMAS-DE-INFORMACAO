CREATE TABLE consulta(
cod_consulta SERIAL NOT NULL,
cod_medico INT NOT NULL,
cod_paciente INT NOT NULL,
data date NULL
);

CREATE TABLE paciente(
cod_paciente SERIAL NOT NULL,
nome varchar(255) NOT NULL,
cpf char(14) NOT NULL
);

CREATE TABLE medico(
cod_medico SERIAL NOT NULL,
CRM char(10) NOT NULL,
nome varchar(255) NOT NULL
);

CREATE TABLE especialidade(
cod_especialidade SERIAL NOT NULL,
tipo varchar(255) NOT NULL
);

CREATE TABLE plano(
cod_plano SERIAL NOT NULL,
nome varchar(255) NOT NULL
);

CREATE TABLE medicamento(
cod_medicamento SERIAL NOT NULL,
nome varchar(255) NOT NULL
);

CREATE TABLE doenca(
cod_doenca SERIAL NOT NULL,
nome varchar(255) NOT NULL
);

