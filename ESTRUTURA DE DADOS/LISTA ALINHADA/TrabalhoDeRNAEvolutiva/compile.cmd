@ECHO OFF
set /p versao=Insira a versao: V
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ rascunho.cpp -o "builds/RascunhoTrabalhoDeRNAEvolutiva.V%versao%.exe"
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/TrabalhoDeRNAEvolutiva.V%versao%.exe"
msg * /v /w RascunhoTrabalhoSistemaDeAlunos.V%versao%.exe foi compilado!
start "builds/RascunhoTrabalhoDeRNAEvolutiva.V%versao%.exe"