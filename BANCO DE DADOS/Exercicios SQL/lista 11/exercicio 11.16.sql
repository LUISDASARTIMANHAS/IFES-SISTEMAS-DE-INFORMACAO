-- select uf_cliente
-- from cliente
-- where uf_cliente = 'MG'
-- 11.16

BEGIN TRANSACTION 

delete from locacao loc
where exists (
	select *
	from cliente cli
	where  loc.cod_cliente = cli.cod_cliente
	and uf_cliente = 'MG'
);

delete from cliente
where uf_cliente = 'MG'


rollback