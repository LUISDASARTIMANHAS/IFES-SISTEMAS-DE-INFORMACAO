@ECHO OFF
:autocompile
set versao=1
set fileName=TrabalhoArvoreBinAVL
	cls
	%*
	echo aguardando timeout
	timeout /t 25 > NUL
	echo Version: %versao%
	g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ rascunho.cpp -o "builds/rascunho.V%versao%-autoCompile.exe"
	echo rascunho.V%versao%-autoCompile.exe Compilado!

	g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/%fileName%.V%versao%-autoCompile.exe"
	echo %fileName%.V%versao%-autoCompile.exe Compilado!

	g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/debug.exe"

	tar -a -c -f "zip/%fileName%.zip" *data *.cpp functions.c *builds


goto autocompile
