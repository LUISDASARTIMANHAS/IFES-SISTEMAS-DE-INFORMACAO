@ECHO OFF
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

    mkdir zip
    tar -a -c -f "zip/TrabalhoSistemaDeAlunos.zip" *data *builds *.cpp functions.c *.cmd
    tar -a -c -f "../TrabalhoSistemaDeAlunos.zip" *data *builds *.cpp functions.c *.cmd
    echo TrabalhoSistemaDeAlunosfoi compactado!

goto autozip