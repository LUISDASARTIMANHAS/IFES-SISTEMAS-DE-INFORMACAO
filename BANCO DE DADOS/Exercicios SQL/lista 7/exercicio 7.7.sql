-- 7. 7. Exiba o código e nome dos clientes que realizaram mais locações do que o cliente 160.
-- código e nome dos clientes que realizaram mais locações
select
	count(*) as "qtde",
	cod_cliente,
	nom_cliente
from
	cliente
group by
	cod_cliente
having
	count(*) > (
		-- 	locações do que o cliente 160
		select
			count(*)
		from
			cliente
		where
			cod_cliente = 160
	)