-- select
-- *
-- from empregado e1
-- where 
-- exists (
-- 	select 
-- 	max(e2.sal_empregado) 
-- 	from empregado e2
-- 	group by e2.cod_departamento
-- 	HAVING e1.sal_empregado = max(e2.sal_empregado) 
-- )
select
	*
from
	empregado e1,
	(
		select
			cod_departamento,
			max(sal_empregado) as Maior
		from
			empregado
		group by
			cod_departamento
	) e2
where
	e1.cod_departamento = e2.cod_departamento
	and e1.sal_empregado = Maior
order by
	e1.cod_departamento