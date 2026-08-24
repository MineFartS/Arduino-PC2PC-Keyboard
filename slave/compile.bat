@echo off
cls

set "arduino-cli=%~dp0..\.msys2\usr\bin\arduino-cli.exe"

::===========================================

echo:
echo ----- Installing Libraries -----

"%arduino-cli%" lib install Keyboard

::===========================================

"%~dp0../_compile.bat" slave

