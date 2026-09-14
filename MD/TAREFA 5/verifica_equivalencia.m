function [eh_equiv, ref, sim, trans] = verifica_equivalencia(M)
    n = rows(M);
    ref = 1;
    sim = 1;
    trans = 1;

    % 1. Teste da Reflexividade
    for i = 1:n
        if M(i, i) == 0
            ref = 0;
            break;
        endif
    endfor

    % 2. Teste da Simetria
    for i = 1:n
        for j = 1:n
            if M(i, j) == 1 && M(j, i) == 0
                sim = 0;
                break;
            endif
        endfor
        if !sim, break; endif
    endfor

    % 3. Teste da Transitividade
    for i = 1:n
        for j = 1:n
            for k = 1:n
                if M(i, j) == 1 && M(j, k) == 1
                    if M(i, k) == 0
                        trans = 0;
                        break;
                    endif
                endif
            endfor
            if !trans, break; endif
        endfor
        if !trans, break; endif
    endfor

    % Avaliacao Final
    eh_equiv = ref && sim && trans;

    if eh_equiv
        disp("A relacao e de equivalencia.");
    else
        disp("A relacao NAO e de equivalencia. Motivos:");
        if !ref
            disp("- Falhou na reflexividade.");
        endif
        if !sim
            disp("- Falhou na simetria.");
        endif
        if !trans
            disp("- Falhou na transitividade.");
        endif
    endif
endfunction
