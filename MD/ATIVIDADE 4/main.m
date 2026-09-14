% MAIN Script de execução e teste automatizado do laboratório.

clc; clear;

disp("=== 1. Tabela de Conectivos ===");
disp(tabela_conectivos());

disp("=== 2. Teste do Meu XOR ===");
p2 = [1; 1; 0; 0];
q2 = [1; 0; 1; 0];
disp([p2, q2, meu_xor(p2, q2)]);

disp("=== 3. Leis de De Morgan ===");
printf("De Morgan valido: %d\n\n", de_morgan_conjuncao());

disp("=== 4 e 5. Expressao e Classificacao ===");
p = [1; 1; 1; 1; 0; 0; 0; 0];
q = [1; 1; 0; 0; 1; 1; 0; 0];
r = [1; 0; 1; 0; 1; 0; 1; 0];
E = avalia_expressao(p, q, r);
disp([p, q, r, E]);
printf("Classificacao: %s\n\n", classifica_proposicao(E));

disp("=== 6. Teste de Equivalencia ===");
sao_equivalentes(E, E);
sao_equivalentes(E, ~E);
