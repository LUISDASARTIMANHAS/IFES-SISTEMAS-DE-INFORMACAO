-- 8.18. Exiba o nome do gênero e o total de locações de cada gênero.
-- 18) Ordenado pelo “total de locações”.
-- nom_genero total
-- Ação 322927
-- Romance 322466
-- Comédia 320755
-- Drama 317839
-- Suspense 316604
-- Policial 316330
-- Aventura 313024
-- Guerra 309041
SELECT
	gen.nom_genero,
	count(loc.cod_locacao) as qtde_Locacoes
FROM
	locacao loc
	JOIN fita fit ON fit.cod_fita = loc.cod_fita
	JOIN filme fil ON fil.cod_filme = fit.cod_filme
	JOIN genero gen ON gen.cod_genero = fil.cod_genero
GROUP BY
	gen.nom_genero
ORDER BY
	qtde_Locacoes desc