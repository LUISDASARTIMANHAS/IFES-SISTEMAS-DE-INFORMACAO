% Arquivo: pertence_conjunto.m
clc; % Limpa a tela
clear; % Limpa o espaço de trabalho
% Definindo um conjunto como um vetor
Conjunto = [2, 4, 6, 8, 10];
elemento = input('Digite um número para verificar se pertence ao conjunto: ');
encontrado = false;
for i = 1:length(Conjunto)
  if Conjunto(i) == elemento
  encontrado = true;
  break;
  end
end
if encontrado
  fprintf('O elemento %d PERTENCE ao conjunto!\n', elemento);
else
  fprintf('O elemento %d NÃO pertence ao conjunto.\n', elemento);
end
