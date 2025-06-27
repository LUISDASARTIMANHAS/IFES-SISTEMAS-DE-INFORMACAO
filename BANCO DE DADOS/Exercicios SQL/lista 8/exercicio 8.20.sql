-- 8.20. Exiba o nome dos clientes que nunca locaram filmes.
-- 20) Tem 35.054 clientes. Ordenado pelo “cod_cliente”. Vou listar os 5 primeiros:
-- cod_cliente nom_cliente
-- 50785 Carla Louzada
-- 52675 Carolina Filetti
-- 53947 Christiane Machado
-- 53963 Christiane Malini
-- 55307 Camila Scalpelli
SELECT
	cli.cod_cliente,
	cli.nom_cliente
FROM
	cliente cli
	LEFT JOIN locacao loc ON loc.cod_cliente = cli.cod_cliente
	-- Mostra só quem nunca alugou
WHERE
	loc.cod_cliente IS NULL
GROUP BY
	cli.cod_cliente,
	cli.nom_cliente
ORDER BY
	cli.cod_cliente