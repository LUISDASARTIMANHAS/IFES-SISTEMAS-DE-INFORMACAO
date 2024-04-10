@ECHO OFF
set /p versao=Insira a versao: 
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o builds/trabalhoSistemaDeAlunos.V%versao%.exe
msg * /v /w trabalhoSistemaDeAlunos.V%versao%.exe foi compilado!
start builds/trabalhoSistemaDeAlunos.V%versao%.exe