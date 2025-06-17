-- 7. 22. Liste o código do empregado e seu total de horas alocadas em projetos. Não devem ser
-- considerados nos cálculos horas dos projetos 10 e 20. Não podem ser exibidos empregados
-- demitidos. Renomeie a segunda coluna para “Quantidade de Horas”. O resultado deve estar
-- ordenado pela quantidade de horas em ordem decrescente. (DEVE SER UTILIZADO O EXISTS)
select
	cod_empregado,
	sum(qtd_horas) as "Quantidade de Horas"
from
	trabalha_em
where
	cod_empregado not in (10, 20)
	and cod_empregado in (
		-- 	 empregados que não foram demitidos
		select
			cod_empregado
		from
			empregado
		where
			dat_demissao is null
	)
group by
	cod_empregado
order by
	"Quantidade de Horas" desc