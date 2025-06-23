-- 4. 5. Exiba o nome dos clientes e seus endereços. O endereço deve ser exibido concatenando o 
-- endereço, bairro, cidade e UF. Nomear esta coluna como “Endereco_completo”.
select concat(rua_cliente,', ',bai_cliente,', ',cid_cliente,', ',uf_cliente) as Endereco_completo
from cliente