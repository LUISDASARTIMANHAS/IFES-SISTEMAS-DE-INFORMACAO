-- 5.3. Exiba o código do cliente, o código da fita, o valor original da locação e o
-- valor da locação acrescido de 10% das fitas locadas em março de 2003.
select
	cod_cliente,
	cod_fita,
	val_locacao,
	val_locacao + (val_locacao * 0.1)
from
	locacao
where
	(
		EXTRACT(
			MONTH
			FROM
				dat_locacao
		) = '03'
		and EXTRACT(
			YEAR
			FROM
				dat_locacao
		) = '2003'
	)
	OR (dat_locacao between '2003-03-01' and '2003-03-31')