/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:12:13 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/20 13:51:55 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../checker.h"

// checks whether input is the same as the operations

void	check_operations(t_stack *stack, char *output)
{
	if (!ft_strncmp(output, "pa\n", 4))
		push_b_to_a(stack);
	else if (!ft_strncmp(output, "pb\n", 4))
		push_a_to_b(stack);
	else if (!ft_strncmp(output, "sa\n", 4))
		swap_a(stack->stack_a);
	else if (!ft_strncmp(output, "sb\n", 4))
		swap_b(stack->stack_b);
	else if (!ft_strncmp(output, "ss\n", 4))
		swap_both(stack);
	else if (!ft_strncmp(output, "ra\n", 4))
		rotate_a(&(stack->stack_a));
	else if (!ft_strncmp(output, "rb\n", 4))
		rotate_b(&(stack->stack_b));
	else if (!ft_strncmp(output, "rr\n", 4))
		rotate_both(stack);
	else if (!ft_strncmp(output, "rra\n", 5))
		rev_rotate_a(&(stack->stack_a));
	else if (!ft_strncmp(output, "rrb\n", 5))
		rev_rotate_b(&(stack->stack_b));
	else if (!ft_strncmp(output, "rrr\n", 5))
		rev_rotate_both(stack);
	else
		error_message();
}

void	check_reading(t_stack *stack)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		check_operations(stack, str);
		free (str);
		str = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stack->stack_a) == 1 && !stack->stack_b)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.stack_a = NULL;
	stack.stack_b = NULL;
	if (argc < 2)
		return (0);
	stack.elements_a = argc - 1;
	stack.elements_b = 0;
	if (!parse_args(argv, &stack))
		return (error_message(), 0);
	check_reading(&stack);
	free_lst(stack.stack_a);
	free_lst(stack.stack_b);
	return (EXIT_SUCCESS);
}
