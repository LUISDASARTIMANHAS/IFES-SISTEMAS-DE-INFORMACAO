@ECHO OFF
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

    mkdir zip
    tar -a -c -f "zip/TrabalhoDeRnaEvolutiva.zip" *data *.cpp functions.c *builds
    tar -a -c -f "../TrabalhoDeRnaEvolutiva.zip" *data *.cpp functions.c *builds
    echo TrabalhoDeRnaEvolutiva foi compactado!

goto autozip