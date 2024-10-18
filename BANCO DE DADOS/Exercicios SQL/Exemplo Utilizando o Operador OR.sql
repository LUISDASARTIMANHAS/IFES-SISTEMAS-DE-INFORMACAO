select *
from fita
where (
(sit_fita = 1) or (cod_filme = 7)
)
and dat_aquisicao >= '2001-01-01'