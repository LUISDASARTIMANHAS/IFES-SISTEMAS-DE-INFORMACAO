do
$$
declare
	selected_professor professor%rowtype;
begin
	select *
	from professor
	into selected_professor
where id_professor = 10;
raise notice 'Dados do Professor de ID 10: % %',
	selected_professor.nome,
	selected_professor.id_professor;
end;
$$;