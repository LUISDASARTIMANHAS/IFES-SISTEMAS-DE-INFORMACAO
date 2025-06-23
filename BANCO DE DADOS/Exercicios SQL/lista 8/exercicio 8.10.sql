-- 8.10. Exiba a data de locação, data de devolução, o código do filme, nome do filme, código e nome
-- dos clientes que moram em Minas Gerais.
-- 10) Tem 93466 filmes. Vou listar os 5 primeiros:
select distinct
	l.dat_locacao
,	l.dat_devolucao
,	fil.cod_filme
,	fil.nom_filme
,	c.cod_cliente
,	c.nom_cliente
from
	locacao l
join fita fit
	ON fit.cod_fita = l.cod_fita
JOIN cliente c
	on c.cod_cliente = l.cod_cliente
join filme fil
	on fil.cod_filme = fit.cod_filme
where c.uf_cliente ilike 'MG'