-- 7. 5. Exiba o código e nome dos filmes que possuem mesma cor que os filmes de Suspense.
select *
from filme
where cod_cor in (
	select cod_cor
	from filme
	where cod_genero = (
		select cod_genero
		from genero
		where nom_genero = 'Suspense'
	)
)