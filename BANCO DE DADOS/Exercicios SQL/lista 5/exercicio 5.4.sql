-- 5.4. Exiba o código da fita e o código do filme com situação Disponível (sit_fita = 2), ou seja, que
-- estão na locadora, e possuem data de aquisição anterior a 2005/01/01.

select cod_fita
,		cod_filme
, 		sit_fita
from fita
where sit_fita = 2