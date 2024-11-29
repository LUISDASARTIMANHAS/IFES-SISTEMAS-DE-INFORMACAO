-- Usando OUTER JOIN
SELECT d.nom_departamento, e.nom_empregado
FROM departamento d
LEFT OUTER JOIN empregado e
ON d.cod_departamento = e.cod_departamento