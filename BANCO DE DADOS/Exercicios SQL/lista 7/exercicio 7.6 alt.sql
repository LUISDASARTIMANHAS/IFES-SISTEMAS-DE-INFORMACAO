-- 7. 6. Exiba o código das fitas mais alugadas do que a fita de código 260.
select 
	count(*) as "qtde"
,	cod_fita
from locacao
group by cod_fita
having count(*) > (
	select count(*)
	from locacao
	where cod_fita = 260
)