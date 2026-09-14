function C = uniao_conjuntos(A, B)
% Inicializa o conjunto resultante com os elementos do conjunto A
    C = A;

    % Percorre cada elemento do conjunto B adiciona-o
    for i = 1:length(B)

        % Se o elemento de B nao estiver presente no conjunto C,
        if ~pertence(B(i), C)
            % Concatena o novo elemento ao vetor
            C = [C, B(i)];
        endif
    endfor

endfunction
