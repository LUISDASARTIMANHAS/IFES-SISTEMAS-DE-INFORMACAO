do $$
begin
	for counter in reverse 5..1 loop
		raise notice 'counter: %', counter;
	end loop;
end; $$