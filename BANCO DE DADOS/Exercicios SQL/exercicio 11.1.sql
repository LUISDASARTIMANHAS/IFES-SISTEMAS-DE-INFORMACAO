-- 10 – Instruções DDL
-- 10.1. Crie o banco de dados de acordo com o ER do Sistema da Locadora (exibido acima). Dê o nome de loc001. 
create table dominio(
		cod_dominio varchar(10) NOT NULL
	,	val_dominio int NOT NULL
	,	desc_dominio varchar(100) NOT NULL
)

create table genero(
		cod_genero int NOT NULL
	,	nom_genero varchar(20) NOT NULL
)

create table filme(
		cod_filme int NOT NULL
	,	nom_filme varchar(80) NOT NULL
)

create table cor(
		cod_cor char(2) NOT NULL
	,	nom_cor varchar(20) NOT NULL
	,	val_fita numeric(10,2) NOT NULL
)

create table fita(
		cod_fita int NOT NULL
	,	sit_fita smallint NOT NULL
	,	dat_aquisicao date NOT NULL
)

create table locacao(
		cod_locacao int NOT NULL
	,	dat_locacao date NULL
	,	dat_aquisicao date NULL
	,	dat_prevista_aquisicao date NULL
	,	dat_devolucao date NULL
	,	val_locacao numeric(10,2) NULL
)