-- 7. 3. Exiba o código e nome dos filmes que possuem o mesmo gênero dos filmes que possuem a letra h em seu nome.
select *
from filme fil1
where exists (
			select  cod_genero
			from filme fil2
			where nom_filme ilike 'h%'
			and fil1.cod_genero = fil2.cod_genero
)
