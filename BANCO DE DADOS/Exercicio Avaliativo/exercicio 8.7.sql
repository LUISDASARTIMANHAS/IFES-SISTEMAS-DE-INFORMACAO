-- 8.7. Exiba o código, nome e preço dos filmes do gênero “Aventura"
-- 7) Tem 62 filmes. Vou listar os 5 primeiros:
select
	f.cod_filme,
	f.nom_filme,
	c.val_fita
from
	filme f
	join cor c on c.cod_cor = f.cod_cor
	join genero g on g.cod_genero = f.cod_genero
where
	g.nom_genero ilike 'Aventura'