@ECHO OFF
set /p versao=Insira a versao: 
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ rascunho.cpp -o builds/TrabalhoDeRNAEvolutiva.V%versao%.exe
msg * /v /w trabalhoSistemaDeAlunos.V%versao%.exe foi compilado!
start builds/TrabalhoDeRNAEvolutiva.V%versao%.exe