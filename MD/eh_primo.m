function resultado = eh_primo(n)
    resultado = 1;

    if n < 2
        resultado = 0;
    else
        for i = 2:n-1
            if mod(n, i) == 0
                resultado = 0;
                break;
            endif
        endfor
    endif
endfunction
