CREATE TABLE Medicamento (
    idMedicamento SERIAL NOT NULL PRIMARY KEY,
    nomeMedicamento VARCHAR(100) NOT NULL
);

CREATE TABLE Doenca (
    idDoenca SERIAL NOT NULL PRIMARY KEY,
    nomeDoenca VARCHAR(100) NOT NULL
);

CREATE TABLE Plano (
    idPlano SERIAL NOT NULL PRIMARY KEY,
    nomePlano VARCHAR(100) NOT NULL
);

CREATE TABLE Paciente (
    idPaciente SERIAL NOT NULL PRIMARY KEY,
    nomePaciente VARCHAR(100) NOT NULL,
    CPF VARCHAR(14) NOT NULL,
    telefone VARCHAR(15) NOT NULL
);

CREATE TABLE Medico (
    idMedico SERIAL NOT NULL PRIMARY KEY,
    nomeMedico VARCHAR(100) NOT NULL,
    CRM VARCHAR(13) NOT NULL
);

CREATE TABLE Especialidade (
    idEspecialidade SERIAL NOT NULL PRIMARY KEY,
    nomeEspecialidade VARCHAR(100) NOT NULL
);

CREATE TABLE Consulta (
    idConsulta SERIAL NOT NULL PRIMARY KEY,
    idMedico INT NOT NULL,
    idPaciente INT NOT NULL,
    dataConsulta DATE NOT NULL,
	
    FOREIGN KEY (idMedico) 
		REFERENCES Medico(idMedico) 
			ON DELETE RESTRICT,
			
    FOREIGN KEY (idPaciente) 
		REFERENCES Paciente(idPaciente) 
			ON DELETE RESTRICT
);

CREATE TABLE Receita (
    idConsulta INT NOT NULL,
    idMedicamento INT NOT NULL,
    dose VARCHAR(50) NOT NULL,
    intervaloDose VARCHAR(50) NOT NULL,
	
    PRIMARY KEY (idConsulta, idMedicamento),
	
    FOREIGN KEY (idConsulta) 
		REFERENCES Consulta(idConsulta) 
			ON DELETE RESTRICT,
			
    FOREIGN KEY (idMedicamento) 
		REFERENCES Medicamento(idMedicamento) 
			ON DELETE RESTRICT
);

CREATE TABLE Diagnostico (
    idConsulta INT NOT NULL,
    idDoenca INT NOT NULL,
    descricao VARCHAR(255) NOT NULL,
	
    PRIMARY KEY (idConsulta, idDoenca),
	
    FOREIGN KEY (idConsulta) 
		REFERENCES Consulta(idConsulta) 
			ON DELETE RESTRICT,
	
    FOREIGN KEY (idDoenca) 
		REFERENCES Doenca(idDoenca) 
			ON DELETE RESTRICT
);

CREATE TABLE Plano_Paciente (
    idPlano INT NOT NULL,
    idPaciente INT NOT NULL,
	
    PRIMARY KEY (idPlano, idPaciente),
	
    FOREIGN KEY (idPlano) 
		REFERENCES Plano(idPlano) 
			ON DELETE RESTRICT,
			
    FOREIGN KEY (idPaciente) 
		REFERENCES Paciente(idPaciente) 
			ON DELETE RESTRICT
);

CREATE TABLE Medico_Especialidade (
    idMedico INT NOT NULL,
    idEspecialidade INT NOT NULL,
	
    PRIMARY KEY (idMedico, idEspecialidade),
	
    FOREIGN KEY (idMedico) 
		REFERENCES Medico(idMedico) 
			ON DELETE RESTRICT,
			
    FOREIGN KEY (idEspecialidade) 
		REFERENCES Especialidade(idEspecialidade) 
			ON DELETE RESTRICT
);

