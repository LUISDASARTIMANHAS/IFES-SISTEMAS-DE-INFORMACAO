--  8.9. Exiba o nome e o valor que cada cliente gastou na locadora.
-- 1.351.556
select 
	c.nom_cliente
,	sum(l.val_locacao)
from
	cliente c
join locacao l
	ON l.cod_cliente = c.cod_cliente
GROUP BY 
	c.nom_cliente
,	l.val_locacao