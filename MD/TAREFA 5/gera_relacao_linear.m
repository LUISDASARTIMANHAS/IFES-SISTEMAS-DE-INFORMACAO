function M = gera_relacao_linear(A, B, a, b)
    % Gera a matriz logica de dimensao |A| x |B| para R = {(x, y) in A x B | y = a*x + b}
    nA = length(A);
    nB = length(B);
    M = zeros(nA, nB);

    for i = 1:nA
        for j = 1:nB
            if B(j) == a * A(i) + b
                M(i, j) = 1;
            endif
        endfor
    endfor
endfunction
