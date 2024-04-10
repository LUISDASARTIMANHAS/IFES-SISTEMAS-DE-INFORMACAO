@ECHO OFF
:autocompile
	cls
	%*
	timeout /t 45 > NUL
	g++ -Wall -g3 -Wextra -static -static-libgcc -static-libstdc++ index.cpp -o builds/trabalhoSistemaDeAlunos.V43.exe
goto autocompile