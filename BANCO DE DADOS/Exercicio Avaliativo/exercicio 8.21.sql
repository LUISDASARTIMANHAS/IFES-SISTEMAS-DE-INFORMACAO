-- 8.21. Exiba o nome dos filmes que nunca foram locados.
-- 21) Tem 69 filmes. Ordenado pelo “cod_filme”. Vou listar os 5 primeiros:
-- cod_filme nom_filme
-- 7 A Bela e a Fera
-- 14 A Era do Gelo 3
-- 21 A hospedeira
-- 29 A Malvada
-- 36 A Nova Cinderela
SELECT
	fil.cod_filme,
	fil.nom_filme
FROM
	filme fil
	-- JOIN garante que só pegue filmes com fita
	JOIN fita fit ON fit.cod_filme = fil.cod_filme
	LEFT JOIN locacao loc ON loc.cod_fita = fit.cod_fita
	-- Mostra só quem nunca alugou
WHERE
	loc.cod_locacao IS NULL
GROUP BY
	fil.cod_filme,
	fil.nom_filme
ORDER BY
	fil.cod_filme
	-- busca filmes sem fitas
	-- SELECT
	--     COUNT(*) AS filmes_sem_fita
	-- FROM
	--     filme fil
	-- LEFT JOIN fita fit ON fit.cod_filme = fil.cod_filme
	-- WHERE
	--     fit.cod_fita IS NULL;