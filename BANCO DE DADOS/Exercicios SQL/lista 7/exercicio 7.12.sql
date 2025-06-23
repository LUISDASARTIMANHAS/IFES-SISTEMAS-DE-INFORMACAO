-- 7. 12. Exiba o código do cliente e o nome que mais alugou fitas.
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