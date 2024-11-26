-- 8.2. Exiba a descrição da situação de todos os filmes
select distinct fita.sit_fita
,		filme.nom_filme
FROM fita, filme
where fita.cod_filme = filme.cod_filme