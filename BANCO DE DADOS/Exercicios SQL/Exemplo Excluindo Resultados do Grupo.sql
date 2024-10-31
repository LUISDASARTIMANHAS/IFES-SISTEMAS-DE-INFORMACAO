select 	cod_cliente
-- conta os clientes e adiciona a coluna qtd Clientes
, 		count(cod_cliente) as "qtd Cliente"
-- soma os valores de locação e adiciona a coluna valor
,		sum(val_locacao) valor
from locacao
-- enquanto a dat de locacao estiver entre os valores
where dat_locacao BETWEEN '2004-11-01' and '2004-12-31'
-- agrupa por clientes
group by cod_cliente
-- filtra a quantidade de clientes, se maior que 3 clientes
HAVING count(cod_cliente) > 3