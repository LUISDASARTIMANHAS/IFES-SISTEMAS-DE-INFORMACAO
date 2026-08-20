function C = uniao_conjuntos(A, B)

    C = A;

    for i = 1:length(B)
        if ~pertence(B(i), C)
            C = [C, B(i)];
        endif
    endfor

endfunction
