-- 7. 1. Exiba o código e nome dos clientes que moram no mesmo estado do cliente de código 110.
select
	*
from
	cliente
where
	(
		select
			cod_departamento,
			max(sal_empregado) as Maior
		from
			empregado
		group by
			cod_departamento
	) e2