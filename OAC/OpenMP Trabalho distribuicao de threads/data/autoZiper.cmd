@ECHO OFF
set fileName=TrabalhoComputacional
cd ..
:autozip
	cls
	%*
	echo aguardando timeout
	timeout /t 120 > NUL

	if exist "zip/%fileName%.zip" (
   	del "zip/%fileName%.zip"
	)

    tar -a -c -f "zip/%fileName%.zip" *.md *data *builds *.py *.cmd
    tar -a -c -f "../%fileName%.zip" *.md *data *builds *.py *.cmd
    echo %fileName% foi compactado!

goto autozip
