% Exercício 3: Média Arredondada

clc;
clear;

nota1 = input('Digite a primeira nota: ');
nota2 = input('Digite a segunda nota: ');
nota3 = input('Digite a terceira nota: ');

media = (nota1 + nota2 + nota3) / 3;
media_arredondada = round(media);

fprintf('Média exata: %.2f\n', media);
fprintf('Média arredondada: %d\n', media_arredondada);
