@echo off

::===========================================

set "arduino-cli=%~dp0..\.msys2\usr\bin\arduino-cli.exe"

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
echo ----- Discovering Board -----

:: Scan connected devices, find the one matching your Leonardo FQBN, and parse its COM port
set "TARGET_PORT="
for /f "tokens=1,2" %%A in ('""%arduino-cli%" board list | findstr "leonardo""') do (
    set "TARGET_PORT=%%A"
    echo Found Leonardo board on port: %%A
)

::===========================================

echo:
echo ----- Flashing -----

:: Send the compiled binary straight to the dynamically discovered port
"%arduino-cli%" upload ^
    --port %TARGET_PORT% ^
    --fqbn %fqbn% ^
    "%inofile%"

::===========================================
