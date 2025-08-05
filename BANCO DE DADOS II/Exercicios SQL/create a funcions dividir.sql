create or replace function dividir(
	val1 numeric,							   
	val2 numeric,
	out quocient numeric,
	out  resto numeric
)returns text as $$
	select val1 / val2, MOD(val1,val2);
$$
language sql;

SELECT apagaDisciplina(1000);