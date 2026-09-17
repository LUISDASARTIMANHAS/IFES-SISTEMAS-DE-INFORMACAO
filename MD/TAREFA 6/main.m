% =========================================================================
% SCRIPT PRINCIPAL DE EXECUÇÃO
% Basta rodar 'main' no terminal do Octave se todos os arquivos estiverem
% na mesma pasta.
% =========================================================================

clear; clc;

fprintf("====================================================\n");
fprintf("      RESOLUÇÃO DO LABORATÓRIO DE COMBINATÓRIA      \n");
fprintf("====================================================\n\n");

% --- Exercício 1: Teste de Combinação ---
fprintf("--- Exercício 1 ---\n");
res_ex1 = combinacao(5, 2);
fprintf("combinacao(5, 2) = %d (Esperado: 10)\n\n", res_ex1);

% --- Exercício 2: O Problema do Comitê ---
fprintf("--- Exercício 2 ---\n");
total_comite = combinacao(10, 4);
comites_incompativeis = combinacao(8, 2);
comites_validos = total_comite - comites_incompativeis;
fprintf("1. Total de comitês possíveis: %d\n", total_comite);
fprintf("2. Comitês sem os dois funcionários incompatíveis juntos: %d\n\n", comites_validos);

% --- Exercício 3: Jogo da Loteria ---
fprintf("--- Exercício 3 ---\n");
total_loteria = combinacao(60, 6);
probabilidade = 1 / total_loteria;
fprintf("1. Total de combinações da Loteria C(60, 6): %d\n", total_loteria);
fprintf("2. Probabilidade de acertar com 1 bilhete: %.10e (1 em %d)\n\n", probabilidade, total_loteria);

% --- Exercício 4: Permutações ---
fprintf("--- Exercício 4 ---\n");
perms_ex4 = gerar_permutacoes({'A', 'B', 'C'});
fprintf("Permutações de ['A', 'B', 'C']:\n");
for i = 1:length(perms_ex4)
    fprintf(" [%s]\n", strjoin(perms_ex4{i}, ', '));
endfor
fprintf("\n");

% --- Exercício 5: Anagramas ---
fprintf("--- Exercício 5 ---\n");
dicionario_teste = {'amor', 'ramo', 'mora', 'roma', 'caro', 'orom'};
anagramas_encontrados = encontrar_anagramas('roma', dicionario_teste);
fprintf("Anagramas de 'roma' encontrados:\n");
for i = 1:length(anagramas_encontrados)
    fprintf(" - %s\n", anagramas_encontrados{i});
endfor
fprintf("\n");

% --- Exercício 6: Permutações com Repetição ---
fprintf("--- Exercício 6 ---\n");
fprintf("Permutações únicas de 'AAB': %d\n\n", perm_com_repeticao('AAB'));

% --- Exercício 7: Permutações Circulares ---
fprintf("--- Exercício 7 ---\n");
fprintf("Permutações circulares para 4 elementos: %d\n\n", permutacao_circular(4));

% --- Exercício 8: Gerar Combinações ---
fprintf("--- Exercício 8 ---\n");
combs_ex8 = gerar_combinacoes({'A', 'B', 'C', 'D'}, 2);
fprintf("Combinações de ['A', 'B', 'C', 'D'] tomados 2 a 2:\n");
for i = 1:length(combs_ex8)
    fprintf(" [%s]\n", strjoin(combs_ex8{i}, ', '));
endfor
fprintf("\n");

% --- Exercício 9: Power Set ---
fprintf("--- Exercício 9 ---\n");
pset = power_set({1, 2, 3});
fprintf("Power Set de [1, 2, 3] (Total: %d subconjuntos):\n", length(pset));
for i = 1:length(pset)
    sub = pset{i};
    if isempty(sub)
        fprintf(" []\n");
    else
        fprintf(" [%s]\n", strtrim(sprintf('%d ', [sub{:}])));
    endif
endfor
fprintf("\n");

% --- Exercício 10: O Problema das Senhas ---
fprintf("--- Exercício 10 ---\n");
senhas_com_repeticao = 36 ^ 8;
senhas_sem_repeticao = arranjo(36, 8);
fprintf("1. Senhas com repetição permitida (36^8): %e\n", senhas_com_repeticao);
fprintf("2. Senhas sem repetição permitida A(36, 8): %e\n", senhas_sem_repeticao);
