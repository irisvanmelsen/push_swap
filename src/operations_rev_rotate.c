/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:11 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/03 17:35:13 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_a(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);	
}
