do $$
declare
-- 	sort by 1: title, 2: release year
	sort_type smallint := 1;
	-- return the number of films
	rec_count int:= 10;
	--use to iterate over the film
	rec record;
	-- dynamic query
	query text;
begin
	query:= 'select title, production_year from film';
	if sort_type = 1 then
		query := query || 'order by title';
	elsif sort_type = 2 then
		query := query || 'order by production_year';
	else
		raise 'invalid sort type %s', sort_type;
	end if;
		query := query || 'limit $1';
	for rec in execute query using rec_count
	loop
		raise notice '% %', rec.production_year, rec.title;
	end loop;
end;
$$