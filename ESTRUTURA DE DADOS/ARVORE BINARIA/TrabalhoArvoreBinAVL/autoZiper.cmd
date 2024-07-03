@ECHO OFF
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

    mkdir zip
    tar -a -c -f "zip/TrabalhoArvoreBinAVL.zip" *data *builds *.cpp functions.c *.cmd
    tar -a -c -f "../TrabalhoArvoreBinAVL.zip" *data *builds *.cpp functions.c *.cmd
    echo TrabalhoArvoreBinAVL foi compactado!

goto autozip