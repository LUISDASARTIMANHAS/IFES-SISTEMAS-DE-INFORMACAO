-- 5.7. Exiba o o código e o nome dos filmes que terminam com a letra S. 
select cod_filme
,      nom_filme
from filme
where nom_filme ilike '%s'