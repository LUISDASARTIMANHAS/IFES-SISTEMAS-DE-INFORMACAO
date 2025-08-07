-- O exemplo a seguir usa uma instrução if else para verificar se uma consulta retorna alguma linha:
do $$
declare
	Professor_selecionado professor%rowtype;
	input_id_professor professor.id_professor%type = 35;
begin
	select *
	from Professor
	into Professor_selecionado
	where id_professor = input_id_professor;
	if not found then
		raise notice '10 professor % NAO ENCONTRADO!',
		input_id_professor;
	else
		raise notice 'O nome do PROFESOR eh %', Professor_selecionado. Nome;
end if;
end $$;