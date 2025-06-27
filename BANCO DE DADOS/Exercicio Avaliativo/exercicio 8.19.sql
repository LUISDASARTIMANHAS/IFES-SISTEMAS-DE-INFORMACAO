-- 8.19. Exiba o código e nome do filme mais alugado.
-- 19) Ordenado pelo “total de locações” e limitado aos dois primeiros registros. 
-- cod_filme nom_filme total
-- 322 O Espetacular HomemAranha 7622
-- 329 O Grande Lebowski 7622
SELECT
	fil.nom_filme,
	count(loc.cod_locacao) as total_locacoes
FROM
	locacao loc
	JOIN fita fit ON fit.cod_fita = loc.cod_fita
	JOIN filme fil ON fil.cod_filme = fit.cod_filme
	JOIN genero gen ON gen.cod_genero = fil.cod_genero
GROUP BY
	fil.nom_filme
ORDER BY
	total_locacoes desc