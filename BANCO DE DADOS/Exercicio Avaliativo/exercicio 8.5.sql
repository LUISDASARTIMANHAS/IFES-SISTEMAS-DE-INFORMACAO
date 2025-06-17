-- 8.5. Exiba o nome do filme e o código da cor dos filmes com situação Disponível (sit_fita = 2), ou
-- seja, que estão na locadora.
select
	f.nom_filme
,	f.cod_cor
,	fit.sit_fita
from
	filme f
join fita fit
	on fit.cod_filme = f.cod_filme
where
	fit.sit_fita = 2