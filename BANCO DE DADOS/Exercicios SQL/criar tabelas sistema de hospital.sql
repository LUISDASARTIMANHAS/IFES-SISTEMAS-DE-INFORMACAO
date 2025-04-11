CREATE TABLE consulta(
cod_consulta SERIAL NOT NULL PRIMARY KEY,
cod_medico INT NOT NULL,
cod_paciente INT NOT NULL,
data date NULL
);

CREATE TABLE paciente(
cod_paciente SERIAL NOT NULL PRIMARY KEY,
nome varchar(255) NOT NULL,
cpf char(14) NOT NULL
);

CREATE TABLE medico(
cod_medico SERIAL NOT NULL PRIMARY KEY,
CRM char(10) NOT NULL,
nome varchar(255) NOT NULL
);

CREATE TABLE especialidade(
cod_especialidade SERIAL NOT NULL PRIMARY KEY,
tipo varchar(255) NOT NULL
);

CREATE TABLE plano(
cod_plano SERIAL NOT NULL PRIMARY KEY,
nome varchar(255) NOT NULL
);

CREATE TABLE medicamento(
cod_medicamento SERIAL NOT NULL PRIMARY KEY,
nome varchar(255) NOT NULL
);

CREATE TABLE doenca(
cod_doenca SERIAL NOT NULL  PRIMARY KEY,
nome varchar(255) NOT NULL
);

ALTER TABLE 

-- DROP TABLE consulta, doenca,especialidade,medicamento,medico,paciente,plano;