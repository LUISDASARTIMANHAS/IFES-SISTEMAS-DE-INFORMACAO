% SAO_EQUIVALENTES Verfica a equivalência lógica entre dois vetores resultantes.
%
% @param {vector} V1 Coluna resultado da primeira proposição
% @param {vector} V2 Coluna resultado da segunda proposição
% @return {logical} eq Retorna 1 para equivalentes e 0 para não equivalentes
function eq = sao_equivalentes(V1, V2)
    divergencias = sum(V1 != V2);

    if divergencias == 0
        disp("As proposicoes sao logicamente equivalentes");
        eq = 1;
    else
        fprintf("As proposicoes nao sao equivalentes. Divergencias encontradas: %d\n", divergencias);
        eq = 0;
    endif
endfunction
