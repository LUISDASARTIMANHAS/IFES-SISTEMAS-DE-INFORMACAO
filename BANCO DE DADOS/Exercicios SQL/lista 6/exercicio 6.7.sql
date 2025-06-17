-- 6. 7. Na tabela CLIENTE, quantos dependentes estão cadastrados?
select
	cod_cliente_titular,
	count(*) as "QTDE Dependentes"
from
	cliente
where
	cod_cliente_titular is null
group by
	cod_cliente_titular