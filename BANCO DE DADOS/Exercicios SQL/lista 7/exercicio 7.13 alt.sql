-- 7. 13. Exiba o código e data de aquisição da fita mais alugada
select
	nom_cliente
from
	cliente
where
	cod_cliente in (
		select
			cod_cliente
		from
			locacao
		group by
			cod_cliente
		having
			count(*) = (
				select
					max(Total)
				from
					(
						-- 	mais alugou fitas.
						select
							cod_cliente,
							count(*) as Total
						from
							locacao
						group by
							cod_cliente
					) Locacoes
			)
	)