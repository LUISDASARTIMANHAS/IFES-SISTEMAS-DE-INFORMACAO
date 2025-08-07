do
$$
declare
	rec record;
begin
-- 	seleçao Disciplina
	select id_disciplina, nome, carga_horaria
	into rec
	from Disciplina
	where id_disciplina = 1086;
raise notice '% % %',
	rec.id_disciplina, 
	rec.nome,
	rec.carga_horaria;
end;
$$
language plpgsql;