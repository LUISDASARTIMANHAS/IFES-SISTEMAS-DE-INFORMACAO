function T = tabela_conjuncao()
% Retorna a tabela-verdade completa para p AND q
p = [1; 1; 0; 0];
q = [1; 0; 1; 0];
resultado = p & q;
T = [p, q, resultado];
endfunction
