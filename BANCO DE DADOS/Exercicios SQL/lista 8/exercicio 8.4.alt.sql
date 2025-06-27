-- 8.4. Exiba o nome dos filmes, a descrição de seu gênero, 
-- mas somente para as fitas que estão disponíveis (sit_fita =2) 
select distinct
	filme.nom_filme,
	genero.nom_genero,
	sit_fita
from
	filme
	JOIN genero ON genero.cod_genero = filme.cod_genero
	join fita on fita.cod_filme = filme.cod_filme
	and fita.sit_fita = 1;

-- select distinct sit_fita from fita;