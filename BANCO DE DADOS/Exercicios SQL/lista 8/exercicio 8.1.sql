-- 8.1. Exiba o nome do filme, sua cor e seu preço.
select
	f.nom_filme,
	f.cod_cor,
	c.val_fita,
	c.nom_cor
from
	filme f
	join cor c on c.cod_cor = f.cod_cor