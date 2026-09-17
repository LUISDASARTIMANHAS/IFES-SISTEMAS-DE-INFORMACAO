 % @brief Calcula o número de permutações únicas para strings com repetição.
 % @param str {char} String contendo caracteres repetidos.
 % @return {number} Número de permutações distintas.
function p = perm_com_repeticao(str)
    n = length(str);
    [~, ~, idx] = unique(str);
    counts = accumarray(idx, 1);

    denom = 1;
    for i = 1:length(counts)
        denom = denom * fat(counts(i));
    endfor

    p = fat(n) / denom;
endfunction
