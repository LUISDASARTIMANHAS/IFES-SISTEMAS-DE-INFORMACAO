function quantidade = conta_pares(V)
    quantidade = 0;

    for i = 1:length(V)
        if mod(V(i), 2) == 0
            quantidade = quantidade + 1;
        endif
    endfor
endfunction
