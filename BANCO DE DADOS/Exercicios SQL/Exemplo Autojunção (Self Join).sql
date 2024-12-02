SELECT tit.cod_cliente, 
tit.nom_cliente,
dep.cod_cliente, 
dep.nom_cliente
FROM cliente tit
JOIN cliente dep
ON tit.cod_cliente = dep.cod_cliente_titular