% Exercício 4: Verificador de Paridade

clc;
clear;

numero = input('Digite um número inteiro: ');

if mod(numero, 2) == 0
    fprintf('O número %d é PAR.\n', numero);
else
    fprintf('O número %d é ÍMPAR.\n', numero);
end
