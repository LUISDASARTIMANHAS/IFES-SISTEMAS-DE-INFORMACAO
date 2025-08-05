create or replace function exibeGrade(CURSO integer,GRADE integer)
returns SETOF GRADE_CURRICULAR as $$
	select *
	from GRADE_CURRICULAR
	WHERE ID_CURSO = CURSO
	AND NR_GRADE = GRADE
	ORDER BY 
	ID_CURSO,
	NR_GRADE,
	NR_PERIODO;
$$
language sql;
