 % @brief Encontra anagramas válidos de uma palavra dado um dicionário de teste.
 % @param palavra {char} String contendo a palavra original.
 % @param dicionario {cell} Lista de palavras válidas para teste.
 % @return {cell} Lista de anagramas encontrados.
function anagramas = encontrar_anagramas(palavra, dicionario)
    chars = num2cell(palavra);
    perms = gerar_permutacoes(chars);

    cand_unicos = {};
    for i = 1:length(perms)
        str_cand = strjoin(perms{i}, '');
        if !any(strcmp(cand_unicos, str_cand))
            cand_unicos{end+1} = str_cand;
        endif
    endfor

    anagramas = {};
    for i = 1:length(cand_unicos)
        if any(strcmp(dicionario, cand_unicos{i}))
            anagramas{end+1} = cand_unicos{i};
        endif
    endfor
endfunction
