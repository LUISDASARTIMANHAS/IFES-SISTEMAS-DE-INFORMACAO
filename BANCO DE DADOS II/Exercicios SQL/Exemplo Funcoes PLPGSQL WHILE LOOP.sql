do $$
declare
	counter integer := 0;
begin
	while counter < 5 loop
		raise notice 'Counter %', counter;
		counter:= counter + 1;
	end loop;
end;
$$;