select rua_cliente
,		uf_cliente
,		count(*)
from cliente

group by rua_cliente
,		uf_cliente
order by uf_cliente, rua_cliente