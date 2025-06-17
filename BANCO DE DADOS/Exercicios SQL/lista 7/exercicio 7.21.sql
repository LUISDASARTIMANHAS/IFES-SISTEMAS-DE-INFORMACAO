-- 7. 21. Selecione o nome e o salário de todos os empregados, que não sejam gerentes nem
-- supervisores, e que ganham mais que o menor salário entre os supervisores (um empregado
-- supervisor possui o campo cod_supervisor preenchido). Apresente os dados ordenados pelo
-- salário em ordem decrescente e em seguida pelo nome do empregado (em ordem crescente).
SELECT 
    e.nom_empregado,
    e.sal_empregado
FROM 
    empregado e
WHERE 
    -- Não é gerente
     e.cod_empregado NOT IN (
        SELECT cod_gerente 
        FROM departamento 
        WHERE cod_gerente IS NOT NULL
    )
   AND
    -- Não é supervisor
    e.cod_empregado NOT IN (
        SELECT cod_supervisor 
        FROM empregado 
        WHERE cod_supervisor IS NOT NULL
    )
    AND
    -- Ganha mais que o menor salário entre os supervisores
    e.sal_empregado > (
        SELECT MIN(sal_empregado)
        FROM empregado
        WHERE cod_empregado IN (
            SELECT DISTINCT cod_supervisor
            FROM empregado
            WHERE cod_supervisor IS NOT NULL
        )
    )
ORDER BY 
    e.sal_empregado DESC,
    e.nom_empregado ASC;


-- select * from empregado
-- Na prática, uma subconsulta é só uma pergunta auxiliar para ajudar a responder a principal.