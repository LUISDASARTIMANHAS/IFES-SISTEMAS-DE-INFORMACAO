-- 5.17. Exiba o código e nome dos clientes, que são dependentes, quando satisfizer os seguintes
-- casos:
-- • Se o cliente mora no estado do Rio de Janeiro, o nome deve começar com a letra D;
-- • Se o cliente mora no estado de Minas Gerais, o nome da rua deve ter Platina;
-- • Se o cliente mora no estado de São Paulo, deve ter Silva em seu nome;
-- Os dados devem ser ordenados pelo nome do cliente;

select * 
from cliente
where 
cod_cliente_titular isnull
and 
	(
		uf_cliente like 'RJ' 
	 	and 
		nom_cliente ilike 'D%'
	)
or
	(
		uf_cliente like 'MG' 
	 	and 
		rua_cliente ilike '%Platina%'
	)
or
	(
		uf_cliente like 'MG' 
	 	and 
		rua_cliente ilike '%Platina%'
	)
order by nom_cliente