create or replace function totalDisciplinas(integer)
returns integer as $$
	--
	select 
	count(*) as TOTAL_DE_DISCIPLINAS
	from GRADE_CURRICULAR
	WHERE ID_CURSO = $1
$$
language sql;

select totalDisciplinas(300);