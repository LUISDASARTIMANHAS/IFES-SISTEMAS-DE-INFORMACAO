select
	cli.nom_cliente,
	gen.nom_genero,
	Count(*) qtd_locacao
FROM
	cliente cli
	JOIN locacao loc ON loc.cod_cliente = cli.cod_cliente
	JOIN fita fit ON fit.cod_fita = loc.cod_fita
	JOIN filme fil ON fil.cod_filme = fit.cod_filme
	JOIN genero gen ON gen.cod_genero = fil.cod_genero
WHERE
	cli.cod_cliente = 1
GROUP by
	cli.nom_cliente,
	gen.nom_genero
ORDER by
	3 desc