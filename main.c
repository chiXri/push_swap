#include <stdio.h>
#include "includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack;

    stack.top = NULL;
    stack.size = 0;

    if (!process_input(argc, argv, &stack))
    {
        printf("Error\n");
        return (1);
    }

    // Comprobar que los datos se almacenaron correctamente
    printf("Números en la pila:\n");
    t_node *current = stack.top;
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    return (0);
}
