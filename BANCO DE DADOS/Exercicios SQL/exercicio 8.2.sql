-- 8.2. Exiba a descrição da situação de todos os filmes
select 
	fit.sit_fita
,	fil.nom_filme
FROM
	fita fit,
	filme fil
where 
fit.cod_filme = fil.cod_filme