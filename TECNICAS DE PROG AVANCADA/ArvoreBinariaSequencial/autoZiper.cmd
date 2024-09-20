@ECHO OFF
:: Leitura do nome a partir do arquivo info.json
for /f "tokens=2 delims=:," %%a in ('type info.json ^| findstr /C:"\"name\""') do (
    set "fileName=%%~a"
)

:: Remove espaços em branco ao redor do nome
set "fileName=%fileName: =%"
set "fileName=%fileName:~1,-1%"

:: Verifica se o nome foi obtido corretamente
if "%fileName%"=="" (
    echo Erro: Falha ao obter o nome do arquivo info.json.
    exit /b 1
)
set fileName=TabelaHashEndAberto

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
