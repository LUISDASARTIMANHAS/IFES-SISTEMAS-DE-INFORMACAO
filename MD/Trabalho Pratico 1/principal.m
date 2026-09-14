% PROGRAMA PRINCIPAL - CALCULADORA DE CONJUNTOS
clc;
clear;

A = [];
B = [];
opcao = -1;

while opcao ~= 0
    fprintf('\n======================================\n');
    fprintf('     CALCULADORA DE CONJUNTOS         \n');
    fprintf('======================================\n');
    fprintf('Conjunto A: [ %s ]\n', num2str(A));
    fprintf('Conjunto B: [ %s ]\n', num2str(B));
    fprintf('--------------------------------------\n');
    fprintf('1. Inserir/Alterar os conjuntos A e B\n');
    fprintf('2. Uniao (A U B)\n');
    fprintf('3. Interseccao (A ∩ B)\n');
    fprintf('4. Diferenca (A - B)\n');
    fprintf('5. Diferenca (B - A)\n');
    fprintf('6. Diferenca Simetrica (A Δ B)\n');
    fprintf('7. Produto Cartesiano (A x B)\n');
    fprintf('0. Sair\n');
    fprintf('======================================\n');

    opcao = input('Escolha uma opcao: ');

    switch opcao
        case 1
            A = ler_conjunto('A');
            B = ler_conjunto('B');
        case 2
            R = uniao_conjuntos(A, B);
            fprintf('\nResultado A U B = [ %s ]\n', num2str(R));
        case 3
            R = interseccao_conjuntos(A, B);
            fprintf('\nResultado A ∩ B = [ %s ]\n', num2str(R));
        case 4
            R = diferenca_conjuntos(A, B);
            fprintf('\nResultado A - B = [ %s ]\n', num2str(R));
        case 5
            R = diferenca_conjuntos(B, A);
            fprintf('\nResultado B - A = [ %s ]\n', num2str(R));
        case 6
            R = diferenca_simetrica(A, B);
            fprintf('\nResultado A Δ B = [ %s ]\n', num2str(R));
        case 7
            fprintf('\n');
            P = produto_cartesiano(A, B);
        case 0
            fprintf('\nEncerrando o programa...\n');
        otherwise
            fprintf('\nOpcao invalida! Tente novamente.\n');
    endswitch
endwhile
