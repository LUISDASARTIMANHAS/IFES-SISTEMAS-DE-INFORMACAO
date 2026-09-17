 % @brief Gera o conjunto das partes (Power Set) de uma lista.
 % @param lista {cell} Cell array contendo os elementos do conjunto.
 % @return {cell} Cell array com todos os 2^n subconjuntos.
function ps = power_set(lista)
    n = length(lista);
    ps = {};
    for k = 0:n
        combs = gerar_combinacoes(lista, k);
        ps = [ps; combs];
    endfor
endfunction
