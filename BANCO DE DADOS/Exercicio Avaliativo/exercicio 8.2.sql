-- 8.2. Exiba a descrição da situação de todos os filmes
-- Tem 714 filmes. Vou listar os 5 primeiros, com DISTINCT e ORDER BY pelo nome do filme:
select distinct
	fit.sit_fita,
	fil.nom_filme
from
	filme fil
	join fita fit ON fit.cod_filme = fil.cod_filme