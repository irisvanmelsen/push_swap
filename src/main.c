/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/16 16:23:28 by ivan-mel         ###   ########.fr       */
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
	int		total;

	stack_a = NULL;
	stack_b = NULL;
	total = argc;
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
	printf("stack_a before push:\n");
	print_stack(stack_a);
	printf("------------------\n");
	printf("stack_b before push:\n");
	print_stack(stack_b);
	printf("------------------\n");
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	printf("------------------\n");
	printf("stack_a after push:\n");
	print_stack(stack_a);
	printf("------------------\n");
	printf("stack_b after push:\n");
	print_stack(stack_b);
	printf("------------------\n");
	// printf("------------------\n");
	// print_stack(stack_b);
	// quicksort_a(&stack_a, &stack_b, argc - 1);
	// printf("test1\n");
	// print_stack(stack_a);
	return (EXIT_SUCCESS);
}