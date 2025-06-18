-- 8.3. Exiba o nome dos filmes, seu código, e sua data de locação, 
-- mas somente para as fitas que ainda não foram devolvidas.
select filme.nom_filme
,		filme.cod_filme
, 		fita.sit_fita
, 		loc.dat_locacao
from filme
JOIN fita fita
	ON filme.cod_filme = fita.cod_filme
JOIN locacao loc
	ON fita.cod_fita = loc.cod_fita

-- SELECT fita.cod_fita, fita.nom_fita,
-- fita.cod_genero, genero.dsc_genero
-- FROM fita
-- INNER JOIN genero
-- ON fita.cod_genero = genero.cod_genero