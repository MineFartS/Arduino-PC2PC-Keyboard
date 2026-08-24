@echo off
cls

::===========================================

set "python=%~dp0..\.python\python.exe"

::===========================================

echo:
echo ----- Installing Dependencies -----

"%python%" -m pip install pyserial

::===========================================

echo:
echo ----- Client Session -----

"%python%" EtherkeyClient.py -l

::===========================================

