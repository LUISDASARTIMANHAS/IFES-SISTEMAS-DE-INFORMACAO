-- 5.5. Exiba o código da fita e o código do cliente cuja data de locação não esteja entre os dias 01/10/2003 e 15/10/2003.
select cod_fita
,      cod_cliente
,      dat_locacao
from fita 
where dat_locacao not BETWEEN '01-10-2003' and '15-10-2003'