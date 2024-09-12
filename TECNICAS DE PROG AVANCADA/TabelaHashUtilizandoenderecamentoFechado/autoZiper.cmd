@ECHO OFF
set fileName=tabelaHash
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

    if not exist "data" (
        mkdir data
    )
    if not exist "builds" (
        mkdir builds
    )
    if not exist "zip" (
        mkdir zip
    )   
    tar -a -c -f "zip/%fileName%.zip" *data *builds *.h rascunho *.cpp functions.c *.cmd
    tar -a -c -f "../%fileName%.zip" *data *builds *.h *rascunho *.cpp functions.c *.cmd
    echo %fileName% foi compactado!

goto autozip
