-- 8.10. Exiba a data de locação, data de devolução, o código do filme, nome do filme, código e nome
-- dos clientes que moram em Minas Gerais.
select
	l.dat_locacao
,	l.dat_devolucao
,	fil.cod_filme
from
	locacao l
join fita fit
	ON fit.cod_fita = l.cod_fita
join fil
	on fil.