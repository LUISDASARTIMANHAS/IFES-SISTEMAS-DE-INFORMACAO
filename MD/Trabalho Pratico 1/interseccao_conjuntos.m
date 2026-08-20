function C = interseccao_conjuntos(A, B)
    % INTERSECCAO_CONJUNTOS Retorna os elementos presentes simultaneamente em A e B.
    % @param {vector} A - Conjunto A.
    % @param {vector} B - Conjunto B.
    % @return {vector} C - Interseccao (A ∩ B).

    C = [];
    for i = 1:length(A)
        if pertence(A(i), B)
            C = [C, A(i)];
        endif
    endfor
endfunction
