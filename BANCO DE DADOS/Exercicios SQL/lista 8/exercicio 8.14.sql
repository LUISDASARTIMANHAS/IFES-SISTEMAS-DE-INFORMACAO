-- 8.14. Exiba o nome do cliente, seu código e o nome dos filmes alugados por ele. Mostre também os
-- clientes que nunca alugaram filmes.
-- 14) Tem 2.574.040 filmes. Ordenado pelo “cod_cliente” e “nom_filme”. Vou listar os 5
-- primeiros:
SELECT
    c.cod_cliente,
    c.nom_cliente,
    f.nom_filme
FROM
    cliente c
    LEFT JOIN locacao l ON c.cod_cliente = l.cod_cliente
    LEFT JOIN fita ft ON l.cod_fita = ft.cod_fita
    LEFT JOIN filme f ON ft.cod_filme = f.cod_filme
ORDER BY
    c.cod_cliente;