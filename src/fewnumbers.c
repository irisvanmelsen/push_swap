/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewnumbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:51:44 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/01 17:51:03 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a_three(t_stack *stack)
{
	printf("test sort three\n");
	if (stack->nb > stack->next->nb
		&& stack->next->nb > stack->next->next->nb)
	{
		sa(&stack);
		print_stack(stack);
		printf("------------------\n");
		rra(&stack);
		printf("address stack1: %p\n", &stack);
		print_stack(stack);
		printf("address stack1: %p\n", &stack);
		print_stack(stack);
		printf("------------------\n");
	}
	else if (stack->nb - 1 > stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		ra(&stack);
	else if (stack->nb == stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		rra(&stack);
	else if (stack->nb - 1 == stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		sa(&stack);
	else if (stack->nb < stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
	{
		sa(&stack);
		ra(&stack);
	}
}

void	sort_b_three(t_stack *stack)
{
	if (stack->nb < stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
	{
		rb(&stack);
		sb(&stack);
	}
	else if (stack->nb < stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		rb(&stack);
	else if (stack->nb - 1 == stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
		rrb(&stack);
	else if (stack->nb == stack->next->nb - 1
		&& stack->next->nb > stack->next->next->nb)
		sb(&stack);
	else if (stack->nb - 1 > stack->next->nb
		&& stack->next->nb < stack->next->next->nb)
	{
		sb(&stack);
		rb(&stack);
	}
}