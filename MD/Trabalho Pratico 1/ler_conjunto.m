function C = ler_conjunto(nome_conjunto)
    % LER_CONJUNTO Le os elementos informados pelo usuario e trata repetiçoes.
    % @param {string} nome_conjunto - Identificador do conjunto (ex: 'A' ou 'B').
    % @return {vector} C - Conjunto validado sem duplicatas.

    prompt = sprintf('Digite os elementos do conjunto %s (ex: [1 2 3]): ', nome_conjunto);
    entrada = input(prompt);

    if isempty(entrada)
        C = [];
    else
        C = remover_duplicatas(entrada);
    endif
endfunction
