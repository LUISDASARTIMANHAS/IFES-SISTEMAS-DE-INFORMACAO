SELECT cod_fita, nom_filme
FROM filme
WHERE cod_filme IN (
    SELECT cod_filme
    FROM fita
    WHERE cod_fita IN (
        SELECT cod_fita
        FROM locacao
        GROUP BY cod_fita
        HAVING COUNT(*) > (
            SELECT COUNT(*)
            FROM locacao
            WHERE cod_fita = 260
        )
    )
)
ORDER BY cod_fita;