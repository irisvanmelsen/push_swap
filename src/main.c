/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/07 14:28:04 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	// printf("stack_a: %p, stack_b: %p\n", stack_a, stack_b);
	quicksort_a(&stack_a, &stack_b, argc - 1);
	print_stacks(stack_a, stack_b);
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