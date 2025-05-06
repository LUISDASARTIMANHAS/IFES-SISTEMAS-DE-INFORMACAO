-- 4.7 Exiba o nome da cor, o valor e o valor acrescido de 10%. Nomear esta última coluna como “Valor Reajustado”. 
select nom_cor
, val_fita
, val_fita + (val_fita * 0.10) as "Valor Reajustado"
from cor