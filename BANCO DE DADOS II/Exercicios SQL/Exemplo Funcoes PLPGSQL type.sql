-- do
-- $$
-- declare
-- 	disciplina_nome Disciplina.nome%type;
-- 	cargahoraria Disciplina.carga_horaria%type;
-- begin
-- 	select nome, carga_horaria
-- 	from Disciplina
-- 	into disciplina_nome, cargahoraria
-- 	where id_disciplina = 1085;
-- raise notice 'Nome da Disciplina de ID 1085: %... carga horaria: % horas', disciplina_nome, cargahoraria;
-- end; $$;

do 
$$
declare 
	disc_nome disciplina.nome%type;
	cargaHR disciplina.carga_horaria%type;
	id_disc disciplina.id_disciplina%type;
begin
	select
		nome,
		carga_horaria,
		id_disciplina
	from 
		disciplina
	into
		disc_nome,
		cargaHR,
		id_disc
	where id_disciplina = 1085;
raise notice 
	'nome da disciplina de ID %: %... carga horaria: % horas',
	id_disc,
	disc_nome, 
	cargaHR;
	
end; $$;
	