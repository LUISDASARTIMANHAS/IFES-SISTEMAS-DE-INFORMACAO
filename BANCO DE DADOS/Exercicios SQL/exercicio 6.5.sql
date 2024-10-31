-- 6. 5. Quantos clientes moram em São Paulo ou no Rio de Janeiro?
select uf_cliente
,		count(1)
from cliente
where uf_cliente in ('RJ','SP')
group by uf_cliente