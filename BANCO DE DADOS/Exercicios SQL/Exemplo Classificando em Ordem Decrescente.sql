select nom_cliente,
	   bai_cliente as "bairro cli"
from cliente
where cod_cliente in (1000,10000,100000,150000,200000)
order by "bairro cli" desc