-- -----------------------------------------------------
-- Table Cliente
-- -----------------------------------------------------
CREATE TABLE Cliente (
  idCliente SERIAL,
  nomeCliente VARCHAR(255) NOT NULL,
  email VARCHAR(100) NOT NULL,
  telefone VARCHAR(15) NOT NULL,
  PRIMARY KEY (idCliente)
);


-- -----------------------------------------------------
-- Table Veiculo
-- -----------------------------------------------------
CREATE TABLE Veiculo (
  placa CHAR(8) NOT NULL,
  marca VARCHAR(50) NOT NULL,
  modelo VARCHAR(100) NOT NULL,
  atual INT NOT NULL DEFAULT 1,
  idCliente INT NOT NULL,
  PRIMARY KEY (placa),
  
  FOREIGN KEY (idCliente)
    REFERENCES Cliente (idCliente)
    ON DELETE RESTRICT
);


-- -----------------------------------------------------
-- Table Categoria
-- -----------------------------------------------------
CREATE TABLE  Categoria (
  idCategoria SERIAL,
  nomeCategoria VARCHAR(100) NOT NULL,
  custoMaoDeObra FLOAT NOT NULL,
  PRIMARY KEY (idCategoria)
);


-- -----------------------------------------------------
-- Table Funcionario
-- -----------------------------------------------------
CREATE TABLE  Funcionario (
  idFuncionario SERIAL,
  nomeFuncionario VARCHAR(255) NOT NULL,
  cpf VARCHAR(14) NOT NULL,
  telefone VARCHAR(15) NOT NULL,
  idCategoria INT NOT NULL,
  PRIMARY KEY (idFuncionario),
  
  FOREIGN KEY (idCategoria)
    REFERENCES Categoria (idCategoria)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table OrdemServico
-- -----------------------------------------------------
CREATE TABLE  OrdemServico (
  idOrdemServico SERIAL,
  dataServico DATE NOT NULL,
  valorTotal FLOAT NULL,
  idCliente INT NOT NULL,
  placa CHAR(8) NOT NULL,
  PRIMARY KEY (idOrdemServico),
  
  FOREIGN KEY (idCliente)
    REFERENCES Cliente (idCliente)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  
  FOREIGN KEY (placa)
    REFERENCES Veiculo (placa)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table Peca
-- -----------------------------------------------------
CREATE TABLE  Peca (
  idPeca SERIAL,
  descricao VARCHAR(255) NOT NULL,
  preco FLOAT NOT NULL,
  qtde INT NOT NULL,
  PRIMARY KEY (idPeca)
);


-- -----------------------------------------------------
-- Table PecasOrdemServico
-- -----------------------------------------------------
CREATE TABLE  PecasOrdemServico (
  idPeca INT NOT NULL,
  idOrdemServico INT NOT NULL,
  qtde INT NOT NULL,
  PRIMARY KEY (idPeca, idOrdemServico),
  
  FOREIGN KEY (idPeca)
    REFERENCES Peca (idPeca)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  
  FOREIGN KEY (idOrdemServico)
    REFERENCES OrdemServico (idOrdemServico)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);


-- -----------------------------------------------------
-- Table FuncionarioOS
-- -----------------------------------------------------
CREATE TABLE  FuncionarioOS (
  idOrdemServico INT NOT NULL,
  idFuncionario INT NOT NULL,
  qtdeHoras INT NOT NULL,
  custo FLOAT NOT NULL,
  PRIMARY KEY (idOrdemServico, idFuncionario),
  
  FOREIGN KEY (idOrdemServico)
    REFERENCES OrdemServico (idOrdemServico)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  
  FOREIGN KEY (idFuncionario)
    REFERENCES Funcionario (idFuncionario)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
);