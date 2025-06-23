-- 6. 2. Quantas fitas estão disponíveis (situação = 2)?
select count(sit_fita) "Quantidade de Fitas"
from fita
where sit_fita = 2