#!/bin/bash

# Variables
EXECUTABLE="slltest"
SRC="slltest.c"
LIB="../singlyLinkedList/singlylinkedlist.c"
INCLUDE_DIR="../singlyLinkedList" # Ruta al directorio de include, cambia si es necesario

# Compilación
echo "Compiling $SRC with $LIB..."
gcc -o $EXECUTABLE $SRC $LIB -I$INCLUDE_DIR -Wall

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    
    # Ejecutar el programa
    echo "Running tests..."
    ./$EXECUTABLE
    
    # Verificar el código de salida del programa
    if [ $? -eq 0 ]; then
        echo "All tests passed!"
    else
        echo "Some tests failed."
    fi
else
    echo "Compilation failed."
fi
