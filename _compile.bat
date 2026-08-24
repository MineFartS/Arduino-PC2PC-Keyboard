@echo off

::===========================================

set "arduino-cli=%~dp0.msys2\usr\bin\arduino-cli.exe"

set "inofile=%~dp0%1\%1.ino"

set "fqbn=arduino:avr:leonardo"

::===========================================

echo:
echo ----- Installing Build Tools -----

"%arduino-cli%" core install arduino:avr

::===========================================

echo:
echo ----- Compiling -----
echo %inofile%

"%arduino-cli%" compile ^
    --fqbn %fqbn% ^
    --build-property "compiler.cpp.extra_flags=\"-I%~dp0%1\"" ^
    "%inofile%"

::===========================================

echo:
echo ----- Flashing -----

"%arduino-cli%" upload ^
    --port COM3 ^
    --fqbn %fqbn% ^
    "%inofile%"

::===========================================

