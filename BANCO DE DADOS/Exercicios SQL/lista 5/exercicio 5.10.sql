-- 5.10. Exiba o nome, código, bairro e cidade dos clientes de Belo Horizonte que moram no centro.
select 
cod_cliente,
nom_cliente,
bai_cliente,
cid_cliente
from
cliente
where 
cid_cliente ilike 'belo horizonte' 