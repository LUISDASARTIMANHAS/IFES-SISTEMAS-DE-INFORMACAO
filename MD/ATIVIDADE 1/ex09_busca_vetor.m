% Exercício 9: Busca Direta em Vetor

clc;
clear;

vetor = [10, 25, 30, 45, 50, 75, 90];

fprintf('Vetor: ');
fprintf('%d ', vetor);
fprintf('\n');

valor = input('Digite o valor que deseja buscar: ');

encontrado = false;
posicao = 0;

for i = 1:length(vetor)
    if vetor(i) == valor
        encontrado = true;
        posicao = i;
        break;
    end
end

if encontrado
    fprintf('Valor %d encontrado na posição %d.\n', valor, posicao);
else
    fprintf('Valor %d não foi encontrado no vetor.\n', valor);
end
