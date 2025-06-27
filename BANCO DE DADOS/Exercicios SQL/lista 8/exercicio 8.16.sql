-- 8.16. Exiba o nome do filme e a quantidade que cada filme foi alugado. Caso um filme não tenha
-- sido alugado, o mesmo deve aparecer no resultado.
-- 16) Tem 498 filmes. Ordenado pelo “nom_filme”. Vou listar os 5 primeiros:
SELECT
    fil.nom_filme,
    COUNT(loc.cod_locacao) AS qtd_alugado
FROM
    filme fil
    LEFT JOIN fita fit ON fit.cod_filme = fil.cod_filme
    LEFT JOIN locacao loc ON loc.cod_fita = fit.cod_fita
GROUP BY
    fil.nom_filme,
    fil.cod_filme
ORDER BY
    fil.nom_filme