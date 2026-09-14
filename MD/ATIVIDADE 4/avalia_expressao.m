% AVALIA_EXPRESSAO Avalia a fórmula proposicional E = (p ^ q) v (q v ~r).
%
% @param {vector} p Vetor coluna de proposições p
% @param {vector} q Vetor coluna de proposições q
% @param {vector} r Vetor coluna de proposições r
% @return {vector} E Vetor coluna com o resultado da expressão
function E = avalia_expressao(p, q, r)
    E = (p & q) | (q | ~r);
endfunction
