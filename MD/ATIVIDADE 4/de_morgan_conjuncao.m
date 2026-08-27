% DE_MORGAN_CONJUNCAO Prova a equivalência da Lei de De Morgan ~(p ^ q) <=> (~p v ~q).
%
% @return {logical} valido Retorna 1 se válida para todos os casos, 0 caso contrário
function valido = de_morgan_conjuncao()
    p = [1; 1; 0; 0];
    q = [1; 0; 1; 0];

    lhs = ~(p & q);
    rhs = (~p) | (~q);

    valido = all(lhs == rhs);
endfunction
