function [tipo, Minv] = classifica_funcao(M)
    Minv = [];

    % Valida se e funcao: cada elemento do dominio possui exatamente 1 imagem
    e_funcao = all(sum(M, 2) == 1);

    if !e_funcao
        tipo = "NAO E FUNCAO";
        disp("A matriz dada nao representa uma funcao valida.");
        return;
    endif

    % Analisa a soma das colunas para injetividade e sobrejetividade
    soma_colunas = sum(M, 1);
    e_injetora = all(soma_colunas <= 1);
    e_sobrejetora = all(soma_colunas >= 1);

    if e_injetora && e_sobrejetora
        tipo = "BIJETORA";
        Minv = M'; % Matriz inversa de f
    elseif e_injetora
        tipo = "INJETORA";
    elseif e_sobrejetora
        tipo = "SOBREJETORA";
    else
        tipo = "APENAS FUNCAO";
    endif
endfunction
