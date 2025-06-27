-- 8.13. Exiba o nome do cliente, seu código e o código das fitas alugadas por ele. Mostre também os
-- clientes que nunca alugaram fitas.
-- Tem 2.574.040 filmes. Ordenado pelo “cod_fita” e “cod_cliente”. Vou listar os 5
-- primeiros:
SELECT
    cli.nom_cliente,
    cli.cod_cliente,
    fit.cod_fita
FROM
    cliente cli
    LEFT JOIN locacao l ON cli.cod_cliente = l.cod_cliente
    LEFT JOIN fita fit ON fit.cod_fita = l.cod_fita
ORDER BY
    fit.cod_fita,
    cli.cod_cliente;