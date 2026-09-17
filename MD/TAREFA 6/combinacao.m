% @brief Calcula a combinação simples C(n, k).
% @param n {number} Total de elementos do conjunto.
% @param k {number} Tamanho dos subconjuntos.
% @return {number} Número total de combinações possíveis.
function c = combinacao(n, k)
    if n < k || n < 0 || k < 0
        error("Erro: 'n' deve ser maior ou igual a 'k' e ambos não negativos.");
    endif
    c = fat(n) / (fat(k) * fat(n - k));
endfunction
