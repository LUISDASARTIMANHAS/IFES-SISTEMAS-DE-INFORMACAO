-- 1. Consulta em duas tabelas com GROUP BY
-- Enunciado: Em um hospital, é importante monitorar a carga de trabalho dos médicos. 
-- Para isso, precisamos saber quantas receitas cada médico prescreveu. 
-- Elabore uma consulta que retorne o nome de cada médico e o total de receitas que eles
-- prescreveram, agrupando os resultados pelo nome do médico. 
SELECT med.nomeMedico
, 	   COUNT(rec.idMedicamento) AS totalReceitas
FROM Medico med
	JOIN Consulta cons 
		ON med.idMedico = cons.idMedico
	JOIN Receita rec 
		ON rec.idConsulta = cons.idConsulta
GROUP BY med.nomeMedico;

-- 2. Consulta em duas tabelas com GROUP BY e HAVING
-- Enunciado: Para avaliar a eficiência dos planos de saúde, a administração do hospital 
-- deseja identificar quais planos têm mais de 10 pacientes cadastrados. Crie uma consulta 
-- que retorne o nome dos planos e o total de pacientes associados a cada plano, agrupando os 
-- resultados pelo nome do plano e filtrando aqueles que não atingem esse número.
SELECT pl.nomePlano
, 	   COUNT(pac.idPaciente) AS totalPacientes
FROM Plano pl
	JOIN Plano_Paciente pp
		ON pl.idPlano = pp.idPlano
	JOIN Paciente pac
		ON pp.idPaciente = pac.idPaciente
GROUP BY pl.nomePlano
HAVING COUNT(pac.idPaciente) > 10;

-- 3. Consulta envolvendo três tabelas
-- Enunciado: O hospital deseja analisar a relação entre pacientes, médicos e diagnósticos. 
-- Elabore uma consulta que retorne o nome de cada paciente, o nome do médico que os atendeu e 
-- a descrição do diagnóstico feito durante a consulta. A consulta deve incluir apenas aqueles 
-- pacientes que têm diagnósticos registrados somente pelas medicas.
SELECT pac.nomePaciente
, 	   med.nomeMedico
, 	   diag.descricao
FROM Paciente pac
	JOIN Consulta cons 
		ON pac.idPaciente = cons.idPaciente
	JOIN Medico med 
		ON cons.idMedico = med.idMedico
	JOIN Diagnostico diag 
		ON cons.idConsulta = diag.idConsulta
WHERE med.nomeMedico LIKE 'Dra.%'

-- 4. Consulta envolvendo LEFT JOIN
-- Enunciado: Para entender melhor a relação entre medicamentos e as receitas prescritas, o hospital 
-- quer listar todos os medicamentos e as receitas que foram feitas para eles, mesmo aqueles que não 
-- têm receitas registradas. 
SELECT medicam.nomeMedicamento
, 	   rec.dose AS dosePrescrita
FROM Medicamento medicam
	LEFT JOIN Receita rec 
		ON medicam.idMedicamento = rec.idMedicamento
ORDER BY dosePrescrita desc;

-- 5. Consulta envolvendo LEFT excluindo JOIN
-- Enunciado: A administração do hospital está interessada em identificar doenças que não foram diagnosticadas
-- em nenhuma consulta até o momento. Crie uma consulta que liste todas as doenças e exclua aquelas que têm 
-- diagnósticos registrados. O resultado deve incluir apenas o nome das doenças que não foram diagnosticadas.
SELECT doe.nomeDoenca
FROM Doenca doe
	LEFT JOIN Diagnostico diag 
		ON doe.idDoenca = diag.idDoenca
WHERE diag.idConsulta IS NULL;
