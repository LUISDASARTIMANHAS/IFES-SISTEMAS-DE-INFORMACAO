-- 8.6. Exiba o nome dos filmes, a descrição de seu gênero, mas somente para as fitas que estão
-- disponíveis (sit_fita =2)
select
	f.nom_filme
,	fit.sit_fita
,	g.nom_genero
from
	filme f
join fita fit
	on fit.cod_filme = f.cod_filme
JOIN genero g
	on g.cod_genero = f.cod_genero
where 
	sit_fita = 2