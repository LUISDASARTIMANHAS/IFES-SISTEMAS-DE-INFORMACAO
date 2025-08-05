create or replace function insereProfessor(integer,varchar(45))
returns integer as $$
	insert into professor(nome,ID_PROFESSOR)
	values ($2,$1);
	
	select $1;
$$
language sql;

select insereProfessor(46,'ANTONIO JONAS PINOTTI');