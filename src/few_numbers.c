/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:46:16 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/03 17:54:15 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a_three(t_stack *stack)
{
	printf("test sort three\n");
	if (stack->nb > stack->next->nb
		&& stack->next->nb > stack->next->next->nb)
	{
		swap_a(&stack);
		print_stack(stack);
		printf("------------------\n");
		rev_rotate_a(&stack);
		printf("address stack1: %p\n", &stack);
		print_stack(stack);
		printf("address stack1: %p\n", &stack);
		print_stack(stack);
		printf("------------------\n");
	}
	else if (stack->nb - 1 > stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		rotate_a(&stack);
	else if (stack->nb == stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		rev_rotate_a(&stack);
	else if (stack->nb - 1 == stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		swap_a(&stack);
	else if (stack->nb < stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
	{
		swap_a(&stack);
		rotate_a(&stack);
	}
}

void	sort_b_three(t_stack *stack)
{
	if (stack->nb < stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
	{
		rotate_b(&stack);
		swap_b(&stack);
	}
	else if (stack->nb < stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		rotate_b(&stack);
	else if (stack->nb - 1 == stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		rev_rotate_b(&stack);
	else if (stack->nb == stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		swap_b(&stack);
	else if (stack->nb - 1 > stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
	{
		swap_b(&stack);
		rotate_b(&stack);
	}
}