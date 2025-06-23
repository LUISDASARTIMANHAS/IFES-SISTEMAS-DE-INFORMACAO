--  8.9. Exiba o nome e o valor que cada cliente gastou na locadora.
-- resultado esperado 335.282
-- 335.282 com group by apenas nome cliente
-- 1.351.556
-- 1.328.344 com distinct
select distinct
	c.nom_cliente
,	sum(l.val_locacao)
from
	cliente c
join locacao l
	ON l.cod_cliente = c.cod_cliente
GROUP BY 
	c.nom_cliente