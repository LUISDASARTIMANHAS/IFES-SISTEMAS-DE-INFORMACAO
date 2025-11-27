@echo off
REM This script installs the required Python packages listed in requirements.txt
python --version
python.exe -m pip install --upgrade pip
pip freeze > requirements.txt
pip install -r requirements.txt
