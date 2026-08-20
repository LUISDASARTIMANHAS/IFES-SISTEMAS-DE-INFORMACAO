function resultado = pertence(elemento, conjunto)

    resultado = false;

    for i = 1:length(conjunto)
        if conjunto(i) == elemento
            resultado = true;
            return;
        endif
    endfor

endfunction
