@ECHO OFF
@REM set /p versao=Insira a versao: V
set versao=5
set fileName=tabelaHash
set fullFileName=%fileName%.V%versao%

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ "rascunho/projetoTabela.cpp" -o "builds/rascunho.exe"

if exist "builds/debug.exe" (
   del "builds/debug.exe"
)
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ tabelaHash.cpp -o "builds/debug.exe"

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ tabelaHash.cpp -o "builds/%fullFileName%.exe"

tar -a -c -f "zip/%fullFileName%.zip" *data *builds *rascunho *.h *.cpp functions.c *.cmd

msg * /v /w %fullFileName%.exe foi compilado!

start "RUN" "builds/%fullFileName%.exe"