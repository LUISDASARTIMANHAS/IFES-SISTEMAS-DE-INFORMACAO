% Exercício 10: Diagonal Principal de uma Matriz Básica

clc;
clear;

M = [1 2 3;
     4 5 6;
     7 8 9];

fprintf('Matriz:\n');
disp(M);

fprintf('Elementos da diagonal principal:\n');

for i = 1:3
    for j = 1:3
        if i == j
            fprintf('%d ', M(i, j));
        end
    end
end

fprintf('\n');
