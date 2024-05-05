@ECHO OFF
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

    mkdir zip
    tar -a -c -f "zip/TrabalhoSistemaDeAlunos.zip" *data *.cpp functions.c *builds
    tar -a -c -f "../TrabalhoSistemaDeAlunos.zip" *data *.cpp functions.c *builds
    echo TrabalhoSistemaDeAlunosfoi compactado!

goto autozip