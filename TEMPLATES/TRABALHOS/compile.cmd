@ECHO OFF
set /p versao=Insira a versao: V

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ rascunho.cpp -o "builds/RascunhoTrabalhoDeRNAEvolutiva.V%versao%.exe"

del "builds/debug.exe"
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/debug.exe"

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/TrabalhoDeRNAEvolutiva.V%versao%.exe"

tar -a -c -f "zip/TrabalhoDeRnaEvolutiva.zip" *data *.cpp functions.c *builds

msg * /v /w RascunhoTrabalhoSistemaDeAlunos.V%versao%.exe foi compilado!

start "builds/RascunhoTrabalhoDeRNAEvolutiva.V%versao%.exe"