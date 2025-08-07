do $$
declare
	rate film.rental_rate%type;
	price_segment varchar(50);
begin
	--get the rental rate
	select rental_rate into rate
	from film
	where film_id = 100;
	--assign the price segment
	if found then
		case rate
			when 0.99 then
				price_segment = 'Mass';
			when 2.99 then
				price_segment = 'Mainstream';
			when 4.99 then
				price_segment = 'High End';
			else
				price_segment = 'Unspecified';
		end case;
		raise notice '%', price_segment;
	else
		raise notice 'film not found';
	end if;
end; $$