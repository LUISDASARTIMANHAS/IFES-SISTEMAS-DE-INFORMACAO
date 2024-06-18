@ECHO OFF
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

    mkdir zip
    tar -a -c -f "zip/TrabalhoDeRnaEvolutiva.zip" *data *builds *.cpp functions.c *.cmd
    tar -a -c -f "../TrabalhoDeRnaEvolutiva.zip" *data *builds *.cpp functions.c *.cmd
    echo TrabalhoDeRnaEvolutiva foi compactado!

goto autozip