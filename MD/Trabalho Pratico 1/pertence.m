function resultado = pertence(elemento, conjunto)
% Retorna true (1) se o elemento estiver no conjunto, ou false
% (0) caso contrario

    resultado = false;

    for i = 1:length(conjunto)
        if conjunto(i) == elemento
            resultado = true;
            % Encerra a busca assim que encontrar
            return;
        endif
    endfor

endfunction
