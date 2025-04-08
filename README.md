# Push_Swap

Push_Swap es un proyecto del programa 42 que consiste en ordenar una pila de enteros utilizando un conjunto limitado de operaciones y la menor cantidad de movimientos posible.

## Objetivo
Crear un programa que tome una lista de números como parámetros, los almacene en una pila (stack A), y los ordene en orden ascendente utilizando otro stack auxiliar (stack B) y un conjunto de operaciones permitidas.

## Estructuras
- `t_stack`: representa una pila (stack A o B)
- `t_node`: nodo de la pila que contiene el valor y su índice

## Operaciones permitidas
- **Swap**
  - `sa`: intercambia los dos primeros elementos de A
  - `sb`: intercambia los dos primeros elementos de B
  - `ss`: `sa` y `sb` al mismo tiempo

- **Push**
  - `pa`: mueve el primer elemento de B a A
  - `pb`: mueve el primer elemento de A a B

- **Rotate**
  - `ra`: desplaza todos los elementos de A hacia arriba
  - `rb`: desplaza todos los elementos de B hacia arriba
  - `rr`: `ra` y `rb` al mismo tiempo

- **Reverse Rotate**
  - `rra`: desplaza todos los elementos de A hacia abajo
  - `rrb`: desplaza todos los elementos de B hacia abajo
  - `rrr`: `rra` y `rrb` al mismo tiempo

## Algoritmos utilizados
- Para 2-3 elementos: ordenaciones simples con `sa`, `ra`, `rra`
- Para 5 elementos: se localizan los dos menores, se llevan a B, se ordena A con 3 elementos, y se devuelve
- Para más de 5 elementos: algoritmo de **Chunks** que divide los índices en bloques y los va enviando a B en orden

## Funcionalidades clave
- `assign_indexes`: Asigna a cada valor un índice ordenado para poder trabajar por posiciones
- `stack_to_array`: Convierte el stack A a un array
- `sort_array`: Ordena el array usando Radix
- `sort_large`: Lógica del algoritmo de chunks (en desarrollo)

## Ejecución
```bash
make
./push_swap 10 3 5 7 2 1
```

## Errores contemplados
- Argumentos no numéricos
- Números duplicados
- Valores fuera del rango de `int`

## Normas
- Cumple Norminette (funciones < 25 líneas, máximo 5 funciones por fichero)
- No se permiten variables globales

## Autor
Marco Chirinos

