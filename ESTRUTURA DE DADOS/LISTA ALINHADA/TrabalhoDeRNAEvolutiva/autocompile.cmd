@ECHO OFF
set versao=8
:autocompile
	cls
	%*
	echo aguardando timeout
	timeout /t 25 > NUL
	echo Version: %versao%
	g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ rascunho.cpp -o "builds/RascunhoTrabalhoDeRNAEvolutiva.V%versao%-autoCompile.exe"
	echo RascunhoTrabalhoDeRNAEvolutiva.V%versao%-autoCompile.exe Compilado!

	g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o "builds/TrabalhoDeRNAEvolutiva.V%versao%-autoCompile.exe"
	echo TrabalhoDeRNAEvolutiva.V%versao%-autoCompile.exe Compilado!

goto autocompile