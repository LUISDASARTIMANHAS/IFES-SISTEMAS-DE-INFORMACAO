@echo off
REM This script installs the required Python packages listed in requirements.txt
python --version

pip freeze > requirements.txt
pip install -r requirements.txt
