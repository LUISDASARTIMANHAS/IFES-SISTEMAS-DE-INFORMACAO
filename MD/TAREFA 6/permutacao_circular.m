 % @brief Calcula permutações de n elementos dispostos em círculo.
 % @param n {number} Quantidade de elementos.
 % @return {number} Número de permutações circulares.
function pc = permutacao_circular(n)
    if n <= 0
        error("Erro: 'n' deve ser maior que zero.");
    endif
    pc = fat(n - 1);
endfunction
