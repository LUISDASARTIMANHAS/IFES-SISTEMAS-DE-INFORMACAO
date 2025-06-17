-- 7.14 
SELECT fil.cod_filme
,		fil.nom_filme
,		count(*) qtdAlugado
FROM locacao loc
JOIN fita fit
	on loc.cod_fita = fit.cod_fita
JOIN filme fil
	ON fil.cod_filme = fit.cod_filme
group by fil.cod_filme
,		fil.nom_filme

HAVING count(*) = (
		select max(qtdAlugado)
		from (
			SELECT fil.cod_filme
			,		fil.nom_filme
			,		count(*) qtdAlugado
			FROM locacao loc
			JOIN fita fit
				on loc.cod_fita = fit.cod_fita
			JOIN filme fil
				ON fil.cod_filme = fit.cod_filme
			group by fil.cod_filme
			,		fil.nom_filme
			) as quantidade
)