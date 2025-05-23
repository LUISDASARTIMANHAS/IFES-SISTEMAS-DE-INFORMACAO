-- 6. 6. Quantos filmes do gênero Aventura (código 4) existem cadastradas?
select
    cod_genero,
    count(*) as "Quantos filmes do gênero Aventura"
from
    filme
where
    cod_genero = 4
group by
    cod_genero