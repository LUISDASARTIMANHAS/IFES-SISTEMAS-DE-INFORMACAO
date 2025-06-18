-- 7. 20. Liste o nome do empregado e a quantidade de horas trabalhadas em projetos. Ordene os
-- dados pela segunda coluna.
select
	nom_empregado
,	(
	select sum(qtd_horas) as "Quantidade de Horas"
	from trabalha_em t1
	where 
	t1.cod_empregado = e1.cod_empregado
	)
from
	empregado e1
where cod_empregado in (
-- 	empregados em projetos
	select distinct
		cod_empregado
	from trabalha_em
	where qtd_horas > 0
)
order by "Quantidade de Horas" desc