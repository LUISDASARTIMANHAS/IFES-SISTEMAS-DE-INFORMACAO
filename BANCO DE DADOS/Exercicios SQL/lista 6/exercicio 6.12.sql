-- 6. 12. Exiba o código do cliente e a quantidade de fitas alugadas para todos os clientes da locadora.
select
	cod_cliente
,	count(*) as "QTDE fitas alugadas para todos os clientes da locadora"
from
	locacao
group by
	cod_cliente
order by
	cod_cliente