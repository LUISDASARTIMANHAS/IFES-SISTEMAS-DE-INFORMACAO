-- 8.15. Exiba a quantidade de fitas que cada cliente alugou. Caso o cliente não tenha alugado
-- nenhuma fita, o mesmo deve aparecer no resultado.
SELECT 
    c.cod_cliente,
    c.nom_cliente,
    f.nom_filme,
	count(c.cod_cliente)
FROM cliente c
LEFT JOIN locacao l
	ON c.cod_cliente = l.cod_cliente
LEFT JOIN fita ft 
	ON l.cod_fita = ft.cod_fita
LEFT JOIN filme f 
	ON ft.cod_filme = f.cod_filme
group by
	c.cod_cliente,
	f.nom_filme
ORDER BY c.cod_cliente;
