-- Exiba o código e nome dos clientes que moram no mesmo estado dos clientes que alugaram
-- fitas no mês de outubro. 
select 
	nom_cliente
,	uf_cliente
from
cliente c1
where c1.uf_cliente in (
	select distinct
	c2.uf_cliente
	from 
	cliente c2
	where
	c2.cod_cliente in (
		select distinct
		cod_cliente
		from locacao
		where EXTRACT (month from dat_locacao ) = 10
	)
)