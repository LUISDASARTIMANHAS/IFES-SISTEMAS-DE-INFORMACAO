-- 8.11. Exiba o código e nome dos filmes de comédia alugadas por clientes do Rio de Janeiro. Mostre
-- também o nome e código desses clientes.
-- resultado esperado 11.870
select
	fil.cod_filme
,	fil.nom_filme
,	c.cod_cliente
,	c.nom_cliente
from cliente c
JOIN locacao l
	on l.cod_cliente = c.cod_cliente
JOIN fita fit
	on fit.cod_fita = l.cod_fita
join filme fil
	on fil.cod_filme = fit.cod_filme
join genero g
	on g.cod_genero = fil.cod_genero
where 
	c.uf_cliente ilike 'RJ'
and 
	g.nom_genero ilike 'Comédia'