-- Comando UNION
-- Exiba todos os clientes cujos nomes iniciam com a
-- letra F e nunca alugaram fitas e os clientes que
-- alugaram mais de 2 fitas.
select nom_cliente, 'Nunca alugou fita' as tipo
from cliente c
where c.nom_cliente like 'F%'
	and not exists ( select 1
					from locacao l
					where c.cod_cliente = l.cod_cliente
				   )
union
select nom_cliente, 'Alugou mais de 2 fitas'
from cliente c
join locacao l
	on c.cod_cliente = l.cod_cliente
group by nom_cliente
having count(*) > 2
order by 1