% =========================================================================
% ROTEIRO DE LABORATÓRIO PRÁTICO: RELAÇÕES E FUNÇÕES NO GNU OCTAVE
% Disciplina: Matemática Discreta
% Professor: Eduardo Max Amaro Amaral | IFES - Campus Colatina
% Script Principal: main.m
% =========================================================================

function main()
    clc;
    opcao = -1;

    while opcao ~= 0
        fprintf("\n");
        disp("=================================================================");
        disp("     MATEMÁTICA DISCRETA - LABORATÓRIO DE RELAÇÕES E FUNÇÕES    ");
        disp("=================================================================");
        disp(" [1] Atividade 1: Gerar Relação Linear y = a*x + b");
        disp(" [2] Atividade 2: Exibir Relação Inversa (R^-1)");
        disp(" [3] Atividade 3: Verificar Reflexividade e Simetria");
        disp(" [4] Atividade 4: Avaliar Relação de Equivalência");
        disp(" [5] Atividade 5: Validar e Classificar Função");
        disp(" [6] Atividade 6: Calcular Composição de Funções (f o g) e (g o f)");
        disp(" [7] Bateria de Testes Automatizada (Executar Todos os Exemplos)");
        disp(" [0] Sair");
        disp("=================================================================");

        opcao = input("Escolha uma opção [0-7]: ");
        fprintf("\n");

        switch opcao
            case 1
                testa_atividade1();
            case 2
                testa_atividade2();
            case 3
                testa_atividade3();
            case 4
                testa_atividade4();
            case 5
                testa_atividade5();
            case 6
                testa_atividade6();
            case 7
                executa_bateria_automatizada();
            case 0
                disp("Saindo do Roteiro Prático... Até logo!");
            otherwise
                disp("Opção inválida! Tente novamente.");
        endswitch

        if opcao ~= 0
            input("\nPressione ENTER para voltar ao menu...", "s");
            clc;
        endif
    endwhile
endfunction

% =========================================================================
% FUNÇÕES AUXILIARES DE TESTE
% =========================================================================

function testa_atividade1()
    disp("--- ATIVIDADE 1: GERAÇÃO DE RELAÇÃO LINEAR ---");
    A = [1, 3, 5, 7];
    B = [3, 5, 7, 9, 11];
    a = 2; b = -3;

    fprintf("Conjunto A = [%s]\n", num2str(A));
    fprintf("Conjunto B = [%s]\n", num2str(B));
    fprintf("Regra da Relação: y = %d*x + (%d)\n\n", a, b);

    M = gera_relacao_linear(A, B, a, b);
    disp("Matriz Lógica Resultante M (|A| x |B|):");
    disp(M);
endfunction

function testa_atividade2()
    disp("--- ATIVIDADE 2: RELAÇÃO INVERSA E PARES ORDENADOS ---");
    A = [1, 3, 5, 7];
    B = [3, 5, 7, 9, 11];
    M = gera_relacao_linear(A, B, 2, -3);

    disp("Matriz Original M:");
    disp(M);

    Minv = exibe_inversa(M, A, B);
    disp("Matriz Transposta (Minv):");
    disp(Minv);
endfunction

function testa_atividade3()
    disp("--- ATIVIDADE 3: REFLEXIVIDADE E SIMETRIA ---");
    disp(">>> Matriz Teste 1 (Reflexiva e Simétrica):");
    M1 = [1, 1, 0; 1, 1, 0; 0, 0, 1];
    disp(M1);
    [refl1, sim1] = verifica_ref_sim(M1);
    fprintf("Reflexiva: %d | Simétrica: %d\n\n", refl1, sim1);

    disp(">>> Matriz Teste 2 (Não Reflexiva, Não Simétrica):");
    M2 = [1, 1, 0; 0, 0, 1; 0, 0, 1];
    disp(M2);
    [refl2, sim2] = verifica_ref_sim(M2);
    fprintf("Reflexiva: %d | Simétrica: %d\n", refl2, sim2);
endfunction

function testa_atividade4()
    disp("--- ATIVIDADE 4: AVALIADOR DE RELAÇÃO DE EQUIVALÊNCIA ---");
    disp(">>> Caso 1: Relação de Equivalência Válida");
    M1 = [1, 1, 0; 1, 1, 0; 0, 0, 1];
    disp("Matriz M1:"); disp(M1);
    [eh_eq1, r1, s1, t1] = verifica_equivalencia(M1);

    disp("\n>>> Caso 2: Falha na Simetria");
    M2 = [1, 1, 0; 0, 1, 0; 0, 0, 1];
    disp("Matriz M2:"); disp(M2);
    [eh_eq2, r2, s2, t2] = verifica_equivalencia(M2);

    disp("\n>>> Caso 3: Falha na Reflexividade e Transitividade");
    M3 = [0, 1, 0; 1, 0, 0; 0, 0, 1];
    disp("Matriz M3:"); disp(M3);
    [eh_eq3, r3, s3, t3] = verifica_equivalencia(M3);
endfunction

function testa_atividade5()
    disp("--- ATIVIDADE 5: VALIDAÇÃO E CLASSIFICAÇÃO DE FUNÇÕES ---");

    disp(">>> Exemplo 1: Função Bijetora");
    M_bij = [1 0 0; 0 1 0; 0 0 1];
    [tipo1, Minv1] = classifica_funcao(M_bij);
    fprintf("Classificação: %s\n", tipo1);
    if !isempty(Minv1)
        disp("Matriz Inversa f^-1:");
        disp(Minv1);
    endif

    disp("\n>>> Exemplo 2: Função Apenas Sobrejetora");
    M_sob = [1 0; 0 1; 0 1]; % 3 elementos no domínio, 2 no contradomínio
    [tipo2, ~] = classifica_funcao(M_sob);
    fprintf("Classificação: %s\n", tipo2);

    disp("\n>>> Exemplo 3: Não é Função (elemento do domínio sem imagem)");
    M_err = [1 0 0; 0 0 0; 0 0 1];
    [tipo3, ~] = classifica_funcao(M_err);
    fprintf("Classificação: %s\n", tipo3);
endfunction

function testa_atividade6()
    disp("--- ATIVIDADE 6: COMPOSIÇÃO DE FUNÇÕES ---");
    x = [0, 1, 2, 3, 4, 5];
    fprintf("Vetor de entrada x = [%s]\n\n", num2str(x));

    [fog, gof] = avalia_composta(x);

    disp("Dadas f(x) = 5x + 1  e  g(x) = x^2:");
    disp("  (f o g)(x) = 5*(x^2) + 1  =>");
    disp(fog);
    disp("  (g o f)(x) = (5x + 1)^2   =>");
    disp(gof);
endfunction

function executa_bateria_automatizada()
    disp("=================================================================");
    disp("       EXECUTANDO BATERIA DE TESTES AUTOMATIZADA COMPLETA        ");
    disp("=================================================================");
    testa_atividade1(); fprintf("\n");
    testa_atividade2(); fprintf("\n");
    testa_atividade3(); fprintf("\n");
    testa_atividade4(); fprintf("\n");
    testa_atividade5(); fprintf("\n");
    testa_atividade6(); fprintf("\n");
    disp("=================================================================");
    disp("             TODOS OS TESTES FORAM CONCLUÍDOS!                   ");
    disp("=================================================================");
endfunction
