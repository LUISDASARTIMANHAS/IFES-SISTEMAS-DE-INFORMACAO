-- 5.9. Exiba o código da fita, o código do cliente e a data de locação das fitas que ainda não foram devolvidas. 
select cod_fita
,      cod_cliente
,      dat_locacao
,      dat_devolucao
from locacao
where dat_devolucao is null


limit 10