function Minv = exibe_inversa(M, A, B)
    % Transpoe a matriz M para obter a matriz da relacao inversa R^-1
    Minv = M';
    [nB, nA] = size(Minv);

    disp("Pares ordenados da Relacao Inversa (R^-1):");
    for j = 1:nB
        for i = 1:nA
            if Minv(j, i) == 1
                fprintf("(%d, %d)\n", B(j), A(i));
            endif
        endfor
    endfor
endfunction
