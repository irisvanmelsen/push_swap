/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/13 16:48:11 by ivan-mel         ###   ########.fr       */
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
	printf("real stack:\n");
	print_stack(stack_a);
	quicksort_a(&stack_a, &stack_b, argc);
	return (EXIT_SUCCESS);
}