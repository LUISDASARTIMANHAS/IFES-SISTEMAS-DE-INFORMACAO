-- 7. 9. Quais filmes que nunca foram locados? (Faça utilizando o comando IN e EXISTS)
select 
* 
from
filme
where
cod_filme in (
	select cod_filme
	from fita
	where cod_fita not in (
		select cod_fita
		from locacao
	)
)