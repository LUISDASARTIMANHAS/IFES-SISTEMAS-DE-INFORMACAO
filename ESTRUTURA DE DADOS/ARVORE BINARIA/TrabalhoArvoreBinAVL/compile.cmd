@ECHO OFF
set /p versao=Insira a versao: V
set fileName=TrabalhoArvoreBinAVL

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ rascunho.cpp -o "builds/%fileName%.V%versao%.exe"

if exist "builds/debug.exe" (
   del "builds/debug.exe"
)
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/debug.exe"

g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/%fileName%.V%versao%.exe"

tar -a -c -f "zip/%fileName%.zip" *data *.cpp functions.c *builds

msg * /v /w %fileName%.V%versao%.exe foi compilado!

start "RUN" "builds/%fileName%.V%versao%.exe"
