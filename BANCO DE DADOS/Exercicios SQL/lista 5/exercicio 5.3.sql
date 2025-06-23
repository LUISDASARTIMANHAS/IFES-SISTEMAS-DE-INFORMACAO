-- 5.3. o código do cliente, o código da fita, o valor original da locação e o valor da locação acrescido de 10% das fitas locadas em março de 2003.
select cod_cliente
,      cod_fita
,      val_locacao         as "Valor Original"
,      (val_locacao * 1.1) as "Valor Corrigido"
,      dat_locacao
from locacao
where dat_locacao BETWEEN '2003-03-01' and '2003-03-31'
limit 5
