-- 7. 1. Exiba o código e nome dos clientes que moram no mesmo estado do cliente de código 110.
select cod_cliente
,		nom_cliente
,		uf_cliente
from cliente cli
where cli.uf_cliente  = (
		select uf_cliente
		from cliente cli2
		where cli2.cod_cliente = 110
)


