-- 6. 11. Exiba o código das fitas, bem como a quantidade de vezes em que cada uma foi alugada.
select
	-- 	quantas vezes o codigo da fita se repete
	cod_fita,
	count(*) as "QTDE filmes cadastrados cada gênero"
from
	locacao
group by
	cod_fita
order by
	cod_fita