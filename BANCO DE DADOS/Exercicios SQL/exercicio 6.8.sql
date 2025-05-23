-- 6. 8. Quantos clientes moram em Vitória?
select
	cid_cliente,
	count(*) as "QTDE clientes moram em Vitória"
from
	cliente
where
	cid_cliente like 'Vitoria'
group by
	cid_cliente