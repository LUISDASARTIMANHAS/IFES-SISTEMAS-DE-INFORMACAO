 % @brief Gera todas as permutações dos elementos de uma lista.
 % @param lista {cell} Cell array com os elementos únicos.
 % @return {cell} Cell array de listas contendo todas as permutações.
function res = gerar_permutacoes(lista)
    n = length(lista);
    if n <= 1
        res = {lista};
        return;
    endif

    res = {};
    for i = 1:n
        elem = lista{i};
        restante = lista([1:i-1, i+1:n]);
        perms_sub = gerar_permutacoes(restante);

        for j = 1:length(perms_sub)
            res{end+1, 1} = [elem, perms_sub{j}];
        endfor
    endfor
endfunction
