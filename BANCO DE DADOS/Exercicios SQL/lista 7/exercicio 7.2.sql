-- 7. 2. Exiba o código e nome dos filmes que possuem a mesma cor do filme
select cod_filme
,		nom_filme
,		cod_cor
from filme film
where exists (
		select cod_cor
		from filme film2
		-- filmes que possuem a mesma cor do filme
		where film.cod_cor = film2.cod_cor
)


