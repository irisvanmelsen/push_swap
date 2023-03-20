/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:11 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/20 13:51:06 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// function that reverse rotates in stack_a

void	rev_rotate_a(t_node **stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}

// function that reverse rotates in stack_b

void	rev_rotate_b(t_node **stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_stack *stack)
{
	rev_rotate(&(stack->stack_a));
	rev_rotate(&(stack->stack_b));
	write(1, "rrr\n", 4);
}
