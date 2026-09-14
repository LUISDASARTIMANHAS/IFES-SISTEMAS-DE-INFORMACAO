% Exercício 7: Somatório de Números

clc;
clear;

soma = 0;
numero = input('Digite um número (0 para parar): ');

while numero ~= 0
    soma = soma + numero;
    numero = input('Digite outro número (0 para parar): ');
end

fprintf('Total acumulado: %.2f\n', soma);
