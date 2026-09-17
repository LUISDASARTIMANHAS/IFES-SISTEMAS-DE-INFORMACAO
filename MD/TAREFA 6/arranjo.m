 % @brief Calcula o arranjo simples A(n, p).
 % @param n {number} Número total de elementos.
 % @param p {number} Quantidade de posições a escolher.
 % @return {number} Número total de arranjos.
function a = arranjo(n, p)
    if p > n || p < 0
        error("Erro: 'p' não pode ser maior que 'p' nem negativo.");
    endif
    a = fat(n) / fat(n - p);
endfunction
