-- 6. 9. Exiba o código do gênero e quantos filmes cadastrados cada gênero possui. Apresente o dado
-- ordenado pelo código do gênero.
select
	cod_genero,
	count(*) as "QTDE filmes cadastrados cada gênero"
from
	filme
group by
	cod_genero
order by
	cod_genero