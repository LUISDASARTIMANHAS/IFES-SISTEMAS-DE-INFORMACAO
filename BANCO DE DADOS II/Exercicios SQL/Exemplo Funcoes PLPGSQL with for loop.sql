do
$$
declare
	rec record;
begin
	for rec in select nome, carga_horaria
		from Disciplina
		where id_disciplina > 1080
		order by nome
	loop
	raise notice '% (%)', rec.nome, rec.carga_horaria;
	end loop;
end;
$$;