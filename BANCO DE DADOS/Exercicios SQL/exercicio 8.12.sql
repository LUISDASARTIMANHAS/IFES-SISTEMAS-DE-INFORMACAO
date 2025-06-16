-- 8.12. Exiba o nome do filme, seu código, a data de sua locação e a data de sua devolução. Mostre
-- também as fitas que nunca foram alugadas.
-- 2539055
select
	fil.cod_filme
,	fil.nom_filme
,	l.dat_locacao
,	l.dat_devolucao
, 	fit.dat_aquisicao
from locacao l
right JOIN fita fit
	on fit.cod_fita = l.cod_fita
JOIN filme fil
	on fil.cod_filme = fit.cod_filme
order by l.dat_locacao desc, fit.cod_fita

-- 2539055
select 
	f.cod_fita,
	f.cod_filme,
	l.dat_locacao,
	l.dat_devolucao
from
fita f
left join locacao l
	on f.cod_fita = l.cod_fita
join filme flm
	on flm.cod_filme = f.cod_filme
order by l.dat_locacao desc, f.cod_fita