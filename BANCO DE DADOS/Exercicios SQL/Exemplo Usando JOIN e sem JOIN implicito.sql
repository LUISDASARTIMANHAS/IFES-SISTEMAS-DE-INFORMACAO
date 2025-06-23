SELECT 
	f.nom_filme
,	f.cod_cor
,	c.nom_cor
,	c.val_fita
,	g.nom_genero
FROM filme f
JOIN cor c
	on f.cod_cor = c.cod_cor
JOIN genero g
	on f.cod_genero = g.cod_genero
where g.nom_genero ilike 'Aventura'

SELECT 
	f.nom_filme
,	f.cod_cor
,	c.nom_cor
,	c.val_fita
,	g.nom_genero
FROM 
	filme f,
	cor c,
	genero g
where
	f.cod_cor = c.cod_cor
and
	f.cod_genero = g.cod_genero
and 
	g.nom_genero ilike 'Aventura'