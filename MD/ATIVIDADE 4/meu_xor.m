% MEU_XOR Implementa a disjunção exclusiva sem utilizar a função nativa xor().
%
% @param {logical|vector} p Valor ou vetor lógico p
% @param {logical|vector} q Valor ou vetor lógico q
% @return {logical|vector} res Resultado de (p v q) ^ ~(p ^ q)
function res = meu_xor(p, q)
    res = (p | q) & ~(p & q);
endfunction
