 % @brief Calcula o fatorial de um número inteiro não negativo.
 % @param n {number} Valor de entrada.
 % @return {number} Resultado de n!
function f = fat(n)
    if n < 0 || floor(n) ~= n
        error("Erro: 'n' deve ser um número inteiro não negativo.");
    endif
    f = 1;
    for i = 1:n
        f = f * i;
    endfor
endfunction
