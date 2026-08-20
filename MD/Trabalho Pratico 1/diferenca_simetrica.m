function C = diferenca_simetrica(A, B)
    % DIFERENCA_SIMETRICA Retorna a diferenca simetrica: (A - B) U (B - A).
    % @param {vector} A - Conjunto A.
    % @param {vector} B - Conjunto B.
    % @return {vector} C - Diferenca Simetrica (A Δ B).

    A_menos_B = diferenca_conjuntos(A, B);
    B_menos_A = diferenca_conjuntos(B, A);

    C = uniao_conjuntos(A_menos_B, B_menos_A);
endfunction
