% CLASSIFICA_PROPOSICAO Classifica uma fórmula proposicional pela sua coluna de resultados.
%
% @param {vector} coluna_resultado Vetor coluna de booleanos
% @return {string} tipo "TAUTOLOGIA", "CONTRADICAO" ou "CONTINGENCIA"
function tipo = classifica_proposicao(coluna_resultado)
    if all(coluna_resultado)
        tipo = "TAUTOLOGIA";
    elseif ~any(coluna_resultado)
        tipo = "CONTRADICAO";
    else
        tipo = "CONTINGENCIA";
    endif
endfunction
