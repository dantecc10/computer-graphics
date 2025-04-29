#!/bin/bash

# Si el primer parámetro es una URL, la descargamos
if [[ "$1" == http* ]]; then
    TEMP_FILE="temp_web_code.c"
    curl -sL "$1" -o "$TEMP_FILE"
    SOURCE="$TEMP_FILE"
else
    SOURCE="$1"
fi

# Verificamos que el archivo fuente exista
if [ ! -f "$SOURCE" ]; then
    echo "Error: archivo '$SOURCE' no encontrado."
    exit 1
fi

# Compilamos y ejecutamos
g++ -o temp "$SOURCE" -lGL -lGLU -lglut
./temp

# Si se pasa la bandera --loop, volvemos a ejecutar
if [ "$2" == "--loop" ]; then
    ./execute-code.sh "$1" --loop
fi
