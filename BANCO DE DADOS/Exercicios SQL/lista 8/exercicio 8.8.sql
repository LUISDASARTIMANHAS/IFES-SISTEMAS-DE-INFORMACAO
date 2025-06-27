-- 8.8. Exiba o código, nome e preço dos filmes disponíveis (sit_fita 2), cujo preço seja maior do que
-- R$ 10,00.
-- 8) Tem 253 filmes. Vou listar os 5 primeiros:
select
	f.cod_filme,
	f.nom_filme,
	c.val_fita
from
	filme f
	join cor c on c.cod_cor = f.cod_cor
	join fita fit on fit.cod_filme = f.cod_filme
where
	fit.sit_fita = 2
	and c.val_fita > 10