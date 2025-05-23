-- 6. 10. Exiba a quantidade de fitas disponíveis (situação igual a 2) e alugadas (situação igual a 1)
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