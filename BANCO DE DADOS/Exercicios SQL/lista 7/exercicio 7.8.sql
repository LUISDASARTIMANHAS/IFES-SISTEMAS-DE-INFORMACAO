-- 7. 8. Quais fitas que nunca foram locadas? (Faça utilizando o comando IN e EXISTS)

select
*
from fita
where cod_fita not in (
	select cod_fita
	from locacao
)