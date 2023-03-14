/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 16:57:16 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main (int argc, char **argv)
{
	t_stack stack;

	// stack = malloc(sizeof(t_stack));
	// stack->stack_a = ft_calloc(1, sizeof(t_node));
	// stack->stack_b = ft_calloc(1, sizeof(t_node));
	stack.stack_a = NULL;
	stack.stack_b = NULL;
	if (argc < 2)
		return (0);
	// printf("main address stack->stack_a: %p\n", stack.stack_a);
	if (!parse_args(argv, &stack))
		return (error_message(), 0);
	// printf("test in main\n");
	// printf("stack_a: %p, stack_b: %p\n", stack_a, stack_b);
	stack.elements_a = argc - 1;
	stack.sort = 0;
	stack.elements_b = 0;
	if (is_sorted(stack.stack_a) == 1)
		return (0);
	quicksort_a(&stack, argc - 1);
	// print_stacks(&stack);
	system("leaks push_swap");
	return (EXIT_SUCCESS);
}

// int	main()
// {
// 	t_stack *stack_c;
// 	int total;

// 	total = 3;
// 	stack_c = NULL;
// 	add_to_end(&stack_c, create_node(3));
// 	add_to_end(&stack_c, create_node(2));
// 	add_to_end(&stack_c, create_node(1));
// 	print_stack(stack_c);
// 	sort_a_three(stack_c);
// }