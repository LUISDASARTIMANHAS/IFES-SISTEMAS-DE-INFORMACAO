-- 11.14.Exclua todos os clientes que nunca locaram fitas
begin TRANSACTION

delete from cliente cli
where not exists (
	select *
	from locacao loc
	where cli.cod_cliente = loc.cod_cliente
)

rollback