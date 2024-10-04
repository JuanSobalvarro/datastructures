@echo off
REM Variables
set EXECUTABLE=slltest.exe
set SRC=slltest.c
set LIB=../singlyLinkedList/singlylinkedlist.c
set INCLUDE_DIR=../singlyLinkedList

REM Compilación
echo Compiling %SRC% with %LIB%...
gcc -o %EXECUTABLE% %SRC% %LIB% -I%INCLUDE_DIR% -Wall

REM Verificar si la compilación fue exitosa
if %errorlevel%==0 (
    echo Compilation successful!
    
    REM Ejecutar el programa
    echo Running tests...
    .\%EXECUTABLE%
    
    REM Verificar el código de salida del programa
    if %errorlevel%==0 (
        echo All tests passed!
    ) else (
        echo Some tests failed.
    )
) else (
    echo Compilation failed.
)
pause
