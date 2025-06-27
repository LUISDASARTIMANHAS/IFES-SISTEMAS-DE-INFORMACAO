-- 8.15. Exiba a quantidade de fitas que cada cliente alugou. Caso o cliente não tenha alugado
-- nenhuma fita, o mesmo deve aparecer no resultado.
-- Tem 373.779 clientes. Ordenado pelo “cod_cliente”. Vou listar os 5 primeiros:
SELECT
    c.cod_cliente,
    c.nom_cliente,
    COUNT(l.cod_fita) AS qtd_fitas_alugadas
FROM
    cliente c
    LEFT JOIN locacao l ON c.cod_cliente = l.cod_cliente
GROUP BY
    c.cod_cliente,
    c.nom_cliente
ORDER BY
    c.cod_cliente;