-- ALTERADA 
-- Exiba o nome e código das fitas que possuem situação de locadas (1) e que possuem gênero 6
-- ou 8.

select distinct 
		fil.nom_filme
,		fit.cod_fita
, 		sit_fita
from filme fil
JOIN fita fit
	ON fil.cod_filme = fit.cod_filme
and fit.sit_fita = 1
and fil.cod_genero in (6,8) 