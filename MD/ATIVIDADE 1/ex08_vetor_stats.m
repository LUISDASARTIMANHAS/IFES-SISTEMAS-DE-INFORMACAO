% Exercício 8: Análise Elementar de Vetor

clc;
clear;

vetor = zeros(1, 5);

for i = 1:5
    vetor(i) = input(sprintf('Digite o %dº número: ', i));
end

soma = sum(vetor);
media = mean(vetor);
maior = max(vetor);
menor = min(vetor);

fprintf('\nVetor: ');
fprintf('%.2f ', vetor);
fprintf('\n');

fprintf('Soma: %.2f\n', soma);
fprintf('Média: %.2f\n', media);
fprintf('Maior elemento: %.2f\n', maior);
fprintf('Menor elemento: %.2f\n', menor);
