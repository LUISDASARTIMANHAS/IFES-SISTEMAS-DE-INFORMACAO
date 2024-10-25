-- 5.13. Exiba o nome e código dos clientes do Rio de Janeiro e São Paulo, ordenados por código.
select cod_cliente
,      nom_cliente
,      uf_cliente
from cliente
where uf_cliente in ('RJ','SP')
order by cod_cliente