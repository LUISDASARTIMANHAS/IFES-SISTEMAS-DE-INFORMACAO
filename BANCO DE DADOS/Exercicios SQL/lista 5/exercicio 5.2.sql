-- 5.2. Exiba o nome, endereço, cidade e estado dos clientes de Minas Gerais que moram em Betim
select
	nom_cliente,
	rua_cliente,
	cid_cliente,
	uf_cliente
from
	cliente
where 
	uf_cliente ilike 'MG'
and
	cid_cliente ilike '%betim%'