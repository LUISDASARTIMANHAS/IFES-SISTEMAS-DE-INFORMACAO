-- 8.16. Exiba o nome do filme e a quantidade que cada filme foi alugado. Caso um filme não tenha
-- sido alugado, o mesmo deve aparecer no resultado.
select
	fil.cod_filme,
	fil.nom_filme,
	Count(*) qtd_alugado
FROM
	filme fil
left join fita fit
	on fit.cod_filme = fil.cod_filme
GROUP by
fil.nom_filme,
fil.cod_filme 
	