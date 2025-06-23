select cod_cliente
, count(*)
from locacao
group by cod_cliente
having count(*) = 1