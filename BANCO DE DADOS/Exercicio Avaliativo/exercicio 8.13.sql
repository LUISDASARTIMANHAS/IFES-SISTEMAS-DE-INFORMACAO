-- 8.12. Exiba o nome do filme, seu código, a data de sua locação e a data de sua devolução. Mostre
-- também as fitas que nunca foram alugadas.
select
	fil.cod_filme
,	fil.nom_filme
,	l.dat_locacao
,	l.dat_devolucao
, 	fit.dat_aquisicao
from locacao l
JOIN fita fit
	on fit.cod_fita = l.cod_fita
JOIN filme fil
	on fil.cod_filme = fit.cod_filme