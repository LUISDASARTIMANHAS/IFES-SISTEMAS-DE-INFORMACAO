create function incrementar(integer)
returns integer as $$
	select $1 + 1;
$$
language sql

select incrementar(10)