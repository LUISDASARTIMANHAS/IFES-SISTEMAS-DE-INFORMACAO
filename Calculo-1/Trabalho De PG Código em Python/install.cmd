@echo off
REM This script installs the required Python packages listed in requirements.txt
python --version
@REM atualiza o python
python.exe -m pip install --upgrade pip


@REM gera as dependencias
pip freeze > requirements.txt
@REM instalar as dependencias
pip install -r requirements.txt
pip install matplotlib numpy