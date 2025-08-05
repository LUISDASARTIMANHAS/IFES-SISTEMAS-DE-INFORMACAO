create or replace function apagaDisciplina(ID INTEGER)
returns text as $$
	delete from 
		DISCIPLINA
	WHERE ID_DISCIPLINA = ID;
	
	select 'A DISCIPLINA ' || ID || ' FOI EXCLUIDA COM SUCESSO!';
$$
language sql;

SELECT apagaDisciplina(1000);