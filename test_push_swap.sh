#!/bin/bash

# Compila (opcional, comenta si ya está compilado)
#make re

echo "🚀 Iniciando pruebas push_swap"

# PRUEBA 1: 100 números aleatorios
echo -e "\n📦 Probando con 100 números aleatorios..."
ARG=$(seq 0 999 | shuf | head -n 100 | tr '\n' ' ')
OPS=$(./push_swap $ARG | wc -l)

echo "🔢 Operaciones usadas: $OPS"
if [ "$OPS" -lt 700 ]; then
    echo "✅ ¡PASASTE la prueba de 100 números! ($OPS operaciones)"
else
    echo "❌ Fallaste en la prueba de 100 números ($OPS operaciones)"
fi

# PRUEBA 2: 500 números aleatorios
echo -e "\n📦 Probando con 500 números aleatorios..."
ARG=$(seq 0 9999 | shuf | head -n 500 | tr '\n' ' ')
OPS=$(./push_swap $ARG | wc -l)

echo "🔢 Operaciones usadas: $OPS"
if [ "$OPS" -lt 5500 ]; then
    echo "✅ ¡PASASTE la prueba de 500 números! ($OPS operaciones)"
else
    echo "❌ Fallaste en la prueba de 500 números ($OPS operaciones)"
fi
