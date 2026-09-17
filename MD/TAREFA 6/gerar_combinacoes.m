 % @brief Gera todas as combinações de tamanho k a partir de uma lista.
 % @param lista {cell} Cell array com elementos do conjunto.
 % @param k {number} Tamanho de cada subconjunto.
 % @return {cell} Cell array de subconjuntos de tamanho k.
function res = gerar_combinacoes(lista, k)
    n = length(lista);
    if k == 0
        res = {{}};
        return;
    endif
    if k > n
        res = {};
        return;
    endif
    if k == n
        res = {lista};
        return;
    endif

    primeiro = lista{1};
    cauda = lista(2:end);

    sub_com = gerar_combinacoes(cauda, k - 1);
    res1 = {};
    for i = 1:length(sub_com)
        res1{end+1, 1} = [primeiro, sub_com{i}];
    endfor

    res2 = gerar_combinacoes(cauda, k);
    res = [res1; res2];
endfunction
