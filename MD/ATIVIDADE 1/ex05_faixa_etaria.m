% Exercício 5: Classificação de Idade

clc;
clear;

idade = input('Digite a idade: ');

if idade >= 0 && idade <= 12
    fprintf('Classificação: Criança\n');
elseif idade >= 13 && idade <= 17
    fprintf('Classificação: Adolescente\n');
elseif idade >= 18 && idade <= 59
    fprintf('Classificação: Adulto\n');
elseif idade >= 60
    fprintf('Classificação: Idoso\n');
else
    fprintf('Idade inválida.\n');
end
