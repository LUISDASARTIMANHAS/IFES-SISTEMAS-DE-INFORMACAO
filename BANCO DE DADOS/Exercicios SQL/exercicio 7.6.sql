select nom_filme
from filme fil
where EXISTS(
	select *
	from fita fit
	where EXISTS (
			select loc.cod_fita
			,	   count(*)
			from locacao loc
			WHERE fit.cod_fita = loc.cod_fita
			GROUP BY loc.cod_fita
			HAVING count(*) > (
				SELECT count(*)
				FROM locacao loc
				WHERE loc.cod_fita = 260
			)
	)
)


-- SELECT cod_fita, nom_filme
-- FROM filme
-- WHERE cod_filme IN (
--     SELECT cod_filme
--     FROM fita
--     WHERE cod_fita IN (
--         SELECT cod_fita
--         FROM locacao
--         GROUP BY cod_fita
--         HAVING COUNT(*) > (
--             SELECT COUNT(*)
--             FROM locacao
--             WHERE cod_fita = 260
--         )
--     )
-- )
-- ORDER BY cod_fita;