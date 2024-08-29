@ECHO OFF
set /p versao=Insira a versao: V
set fileName=listaEncadeadaSimples
set fullFileName=%fileName%.V%versao%

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ rascunho.c -o "builds/rascunho.V%versao%.exe"

if exist "builds/debug.exe" (
   del "builds/debug.exe"
)
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ listaEncadeadaSimples.c -o "builds/debug.exe"

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ listaEncadeadaSimples.c -o "builds/%fullFileName%.exe"

tar -a -c -f "zip/%fullFileName%.zip" *data *builds *.cpp *.c *.cmd *.txt

msg * /v /w %fullFileName%.exe foi compilado!

start "RUN" "builds/%fullFileName%.exe"