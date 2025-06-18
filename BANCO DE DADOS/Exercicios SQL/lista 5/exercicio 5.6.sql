-- 5.6. Exiba o nome e o código do gênero dos filmes 200, 210, 250 e 260.
select nom_filme
,		cod_genero
from filme
where cod_filme in (200, 210, 250,260)
