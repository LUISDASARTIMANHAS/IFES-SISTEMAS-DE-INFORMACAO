function P = produto_cartesiano(A, B)
    % PRODUTO_CARTESIANO Gera e exibe os pares ordenados (a, b) onde a ∈ A e b ∈ B.
    % @param {vector} A - Conjunto A.
    % @param {vector} B - Conjunto B.
    % @return {matrix} P - Matriz N x 2 contendo todos os pares ordenados.

    P = [];

    if isempty(A) || isempty(B)
        fprintf('A x B = {}\n');
        return;
    endif

    fprintf('A x B = { ');
    for i = 1:length(A)
        for j = 1:length(B)
            P = [P; A(i), B(j)];
            fprintf('(%d, %d) ', A(i), B(j));
        endfor
    endfor
    fprintf('}\n');
endfunction
