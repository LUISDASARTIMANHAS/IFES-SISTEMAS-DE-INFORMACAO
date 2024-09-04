set fileName=tabelaHash
if EXIST "debug.exe" (
   del "debug.exe"
) 
g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ %fileName%.cpp -o "/debug.exe"
