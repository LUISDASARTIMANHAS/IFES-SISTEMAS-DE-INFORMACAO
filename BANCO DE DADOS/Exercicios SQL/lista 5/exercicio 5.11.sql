-- 5.11. Exiba o nome e código dos filmes de cor Preta (código PR), ordenado por nome.
select
nom_filme,
cod_filme
from filme
where 
cod_cor like 'PR';