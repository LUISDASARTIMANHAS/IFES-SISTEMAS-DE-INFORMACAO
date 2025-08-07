do $$
declare
	v_film film%rowtype;
	len_description varchar(100);
begin
	select * from film
	into v_film
	where film_id = 100;
	if not found then
		raise notice 'Film not found';
	else
	if v_film.lenght > and v_film.lenght <= 50 then
		len_description := 'Short';
	elsif v_film.lenght > 50 and v_film.lenght < 120 then
		len_description := 'Medium';
	elsif v_film.lenght > 120 then 
		len_description := 'Long';
	else
		len_description := 'N/A';
	end if;
	raise notice 'The % film is %.',
		v_film.title,
		len_description;
	end if;
end $$;