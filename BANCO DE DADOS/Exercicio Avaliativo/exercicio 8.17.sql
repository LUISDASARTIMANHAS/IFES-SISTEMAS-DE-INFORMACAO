-- 8.17. Exiba o nome do cliente, a descrição do gênero e a quantidade de locações feitas por gênero
-- de cada cliente.
-- 17) Tem 1.553.090 locações. Ordenado pelo “nom_cliente”. Vou listar os 5 primeiros:
SELECT
	cli.nom_cliente,
	gen.nom_genero,
	count(loc.cod_locacao) as qtde_Locacoes
FROM
	cliente cli
	JOIN locacao loc ON loc.cod_cliente = cli.cod_cliente
	JOIN fita fit ON fit.cod_fita = loc.cod_fita
	JOIN filme fil ON fil.cod_filme = fit.cod_filme
	JOIN genero gen ON gen.cod_genero = fil.cod_genero
GROUP BY
	gen.nom_genero,
	cli.nom_cliente
ORDER BY
	cli.nom_cliente