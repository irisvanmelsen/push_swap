/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/01 17:52:45 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_message(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		error_message();
		return (0);
	}
	if (!parse_args(argv, &stack_a))
	{
		error_message();
		return (0);
	}
	// printf("stack a in quicksort a before rotate:\n");
	// print_stack(stack_a);
	// printf("------------------\n");
	// sa(&stack_a);
	// rra(&stack_a);
	// printf("stack a in quicksort a after rotate:\n");
	// print_stack(stack_a);
	// printf("------------------\n");
	printf("stack_a: %p, stack_b: %p\n", stack_a, stack_b);
	stack_a->elements = argc - 1;
	// stack_b->elements = 0;
	quicksort_a(&stack_a, &stack_b, argc - 1);
	print_stack(stack_a);
	printf("addresss stack_a: %p\n", stack_a);
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