-- 5.8. Exiba o código e o nome dos clientes que começam com a letra R ou que terminam com a letra O.
select cod_cliente
,      nom_cliente
from cliente
where nom_cliente ilike 'R%'
or nom_cliente ilike '%o'
