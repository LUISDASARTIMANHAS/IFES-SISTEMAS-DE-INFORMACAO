@ECHO OFF

:: Sincroniza com a nuvem antes de enviar
git pull

:: Adiciona todos os arquivos alterados, respeitando o .gitignore
git add .

:: Cria um commit com uma mensagem baseada no nome e versão do mod
git commit -m "Automated commit for LIBS"

:: Envia os arquivos para o repositório remoto na branch especificada
git push origin main

exit /b 0