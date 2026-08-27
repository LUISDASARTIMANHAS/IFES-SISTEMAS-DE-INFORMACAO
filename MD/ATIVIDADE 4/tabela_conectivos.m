% TABELA_CONECTIVOS Gera matriz 4x6 com a tabela-verdade dos conectivos fundamentais.
%
% @return {matrix} T Matriz contendo [p, q, ~p, p&q, p|q, xor(p,q)]
function T = tabela_conectivos()
    p = [1; 1; 0; 0];
    q = [1; 0; 1; 0];

    T = [p, q, ~p, p & q, p | q, xor(p, q)];
endfunction
