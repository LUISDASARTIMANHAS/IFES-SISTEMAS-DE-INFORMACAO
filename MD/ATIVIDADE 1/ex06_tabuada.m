% Exercício 6: Tabuada Personalizada

clc;
clear;

numero = input('Digite um número inteiro: ');

fprintf('\nTabuada do %d:\n', numero);

for i = 1:10
    resultado = numero * i;
    fprintf('%d x %d = %d\n', numero, i, resultado);
end
