#include <stdio.h>
#include "includes/push_swap.h"

#include <stdio.h>
/*
// Función para imprimir la pila
void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {


    t_stack stack;
    init_stack(&stack);

    t_stack stack1;
    init_stack(&stack1);

    // Insertar elementos en la pila
    push_stack(&stack, 10); 
    push_stack(&stack, 20);  
    push_stack(&stack, 30);  
    

      // Insertar elementos en la pila
      push_stack(&stack1, 40); 
      push_stack(&stack1, 50); 
      push_stack(&stack1, 60);  
      
    printf("Pila original a:\n");
    print_stack(&stack); 
    printf("Pila original b:\n");
    print_stack(&stack1);
    printf("\n");

    // Realizamos el push
    move_push(&stack, &stack1);

    printf("Pila después de push en el stack_a:\n ");
    print_stack(&stack);
    printf("Pila después de push en el stack_b:\n ");
    print_stack(&stack1);  

   
   t_stack stack_a;
   init_stack(&stack_a);
   t_stack stack_b;
   init_stack(&stack_b);

    // Insertar elementos en la pila
    push_stack(&stack_a, 5000); 
    push_stack(&stack_a, 10);  
    push_stack(&stack_a, 400);
    push_stack(&stack_a, 70000); 
    push_stack(&stack_a, 100);  
   
 
    

    printf("Pila original a:\n");
    print_stack(&stack_a); 
    //printf("Pila original b:\n");
    //print_stack(&stack_b); 

    //sort_three(&stack_a);
    sort_five(&stack_a,&stack_b);
    printf("Pila después de change en el stack_a:\n ");
    print_stack(&stack_a);

    printf("Pila después de change en el stack_b:\n ");
    print_stack(&stack_b);
    //printf("Pila después de swap en el stack_b:\n ");
    //print_stack(&stack_b);
    return 0;
}
*/
void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);

	if (argc > 1)
	{
		if (!process_input(argc, argv, &stack_a))
		{
			write(2, "Error\n", 6);
			return (1);
		}

		printf("📦 Pila original A:\n");
		print_stack(&stack_a);

		if (stack_a.size == 2)
			sa(&stack_a);
		else if (stack_a.size == 3)
			sort_three(&stack_a);
		else if (stack_a.size == 5)
			sort_five(&stack_a, &stack_b);
        else
            assign_indexes(&stack_a); 

		printf("✅ Pila final A ordenada:\n");
		print_stack(&stack_a);
    
		if (stack_b.top)
		{
			printf("📤 Pila B al final:\n");
			print_stack(&stack_b);
		}
	}
	return (0);
}
