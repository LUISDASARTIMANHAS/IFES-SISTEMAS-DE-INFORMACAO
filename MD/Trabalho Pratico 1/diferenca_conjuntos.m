function C = diferenca_conjuntos(A, B)
    % DIFERENCA_CONJUNTOS Retorna os elementos de A que nao pertencem a B.
    % @param {vector} A - Conjunto base.
    % @param {vector} B - Conjunto a ser subtraido.
    % @return {vector} C - Diferenca (A - B).

    C = [];
    for i = 1:length(A)
        if ~pertence(A(i), B)
            C = [C, A(i)];
        endif
    endfor
endfunction
