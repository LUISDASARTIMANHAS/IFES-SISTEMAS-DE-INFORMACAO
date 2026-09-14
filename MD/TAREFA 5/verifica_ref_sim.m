function [eh_reflexiva, eh_simetrica] = verifica_ref_sim(M)
    % VERIFICA_REF_SIM Verifica se a matriz quadrada M é reflexiva e/ou simétrica
    %
    % Assinatura: function [eh_reflexiva, eh_simetrica] = verifica_ref_sim(M)

    if rows(M) ~= columns(M)
        error("A matriz M deve ser quadrada (|A| x |A|).");
    endif

    eh_reflexiva = all(diag(M) == 1);
    eh_simetrica = isequal(M, M');
endfunction
