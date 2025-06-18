-- exercicio 6.17
select cod_projeto
-- distinct cod_empregado impede que o mesmo empregado seja contado em varios projetos
, 	   count(distinct cod_empregado)
, 	   sum(qtd_horas)
, 	   sum(qtd_horas) * 1.15 as "quantidade de horas adicionadas"
,	   avg(qtd_horas)
from trabalha_em
where qtd_horas is not null
group by cod_projeto
-- Exiba apenas os resultados cuja quantidade de horas, sem a adição de 15%, forem superiores a 200 horas
-- aplica o filtro de exibição 
having sum(qtd_horas) > 200
order by 4 desc