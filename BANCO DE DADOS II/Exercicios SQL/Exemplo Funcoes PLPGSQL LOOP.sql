do $$
declare
	counter int := 0;
begin
	loop
		counter = counter + 1;
		raise notice '%', counter;
		exit when counter = 5;
	end loop;
end;
$$;