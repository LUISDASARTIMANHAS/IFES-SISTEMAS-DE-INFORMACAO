function C = remover_duplicatas(V)
    % REMOVER_DUPLICATAS Garante a unicidade dos elementos de um vetor.
    % @param {vector} V - Vetor original de numeros inteiros.
    % @return {vector} C - Vetor sem elementos duplicados.

    C = [];
    for i = 1:length(V)
        if ~pertence(V(i), C)
            C = [C, V(i)];
        endif
    endfor
endfunction
