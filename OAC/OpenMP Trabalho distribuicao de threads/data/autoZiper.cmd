@ECHO OFF
set fileName=TrabalhoComputacional
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

    tar -a -c -f "zip/%fileName%.zip" *data *builds *.cpp functions.c *.cmd
    tar -a -c -f "../%fileName%.zip" *data *builds *.cpp functions.c *.cmd
    echo %fileName% foi compactado!

goto autozip
