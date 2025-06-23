-- 7.4 Exiba o código e nome dos clientes que moram no mesmo estado dos clientes que alugaram fitas no mês de outubro. 

select *
from cliente cli_geral
where exists (
					select cod_cliente
					from cliente cli
					where EXISTS (
										select cod_cliente
										from locacao loc
										where extract(month from dat_locacao) = 10
										and cli.cod_cliente = loc.cod_cliente
									)
	and cli.uf_cliente = cli_geral.uf_cliente
)