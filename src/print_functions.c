/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:18:09 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 14:51:47 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// test function which prints the stack

void	print_stacks(t_stack *stack)
{
	size_t size_a;
	size_t size_b;
	size_t i;
	size_t i_2;

	size_a = list_size(stack->stack_a);
	size_b = list_size(stack->stack_b);
	i = (size_a > size_b ? size_a - size_b : size_b - size_a);
	i_2 = (size_a > size_b ? size_a - i : size_b - i);
	if (size_a == size_b)
	{
		i_2 = size_a;
		i = 0;
	}
	printf("\tA\tB\n");
	while (i_2)
	{
		printf("\t%d\t%d\n" , stack->stack_a->nb, stack->stack_b->nb);
		i_2--;
		stack->stack_a = stack->stack_a->next;
		stack->stack_b = stack->stack_b->next;
	}
	while (i && size_a > size_b)
	{
		printf("\t%d\n" , stack->stack_a->nb);
		i--;
		stack->stack_a = stack->stack_a->next;
	}
	while (i && size_a < size_b)
	{
			printf("\t\t%d\n" , stack->stack_b->nb);
			i--;
			stack->stack_b = stack->stack_b->next;

	}
	printf("\n\tEND PRINT FUNC\n");
}

// test function which prints the stack

void	print_stack(t_node *stack)
{
	t_node	*start;
	t_node	*end;

	if (!stack)
		return ;
	start = stack;
	end = stack->prev;
	while (start != end)
	{
		// printf("output: %d\n", stack->nb);
		// printf("stack-nb %d | stack->index %d\n", stack->nb, stack->index);
		if (stack == end)
			break ;
		stack = stack->next;
	}
	// printf("output: %d\n", stack->nb);
}

// // test function which prints the index

// void	print_index(t_stack *stack)
// {
// 	t_stack	*start;

// 	if (!stack)
// 		return ;
// 	start = stack;
// 	while (stack)
// 	{
// 		printf("index: %d\n", stack->index);
// 		stack = stack->next;
// 		if (stack == start)
// 			break ;
// 	}
// }

int	stack_length(t_node *stack)
{
	int	i;
	t_node	*start;

	i = 0;
	start = stack;
	while (stack->next != start)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}