-- exercicio 6.21 
select cod_departamento
, 	   count(*) as "Quantidade Empregado"
from empregado
where cod_cargo = 2
and cod_departamento in (40,50)
and sal_empregado between 1000 and 4500
GROUP BY cod_departamento
,		 sal_empregado
HAVING count(*) between 330 and 340
ORDER BY cod_departamento
,		 sal_empregado