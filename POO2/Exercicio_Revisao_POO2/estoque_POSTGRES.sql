
-- -----------------------------------------------------
-- Table Categoria
-- -----------------------------------------------------
CREATE TABLE  Categoria (
  idCategoria SERIAL,
  descricao VARCHAR(100) NOT NULL,
  PRIMARY KEY (idCategoria)
);


-- -----------------------------------------------------
-- Table Produto
-- -----------------------------------------------------
CREATE TABLE  Produto (
  idProduto SERIAL,
  nome VARCHAR(100) NOT NULL,
  quantidade INT NOT NULL,
  preco FLOAT NOT NULL,
  idCategoria INT NOT NULL,
  PRIMARY KEY (idProduto),
  FOREIGN KEY (idCategoria)
    REFERENCES Categoria (idCategoria)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
);


INSERT INTO Categoria (idCategoria, descricao) VALUES (1, 'Bebidas');
INSERT INTO Categoria (idCategoria, descricao) VALUES (2, 'Hortifruti');
INSERT INTO Categoria (idCategoria, descricao) VALUES (3, 'Carnes');

