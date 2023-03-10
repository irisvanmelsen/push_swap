/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:11 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/10 19:54:42 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_a(t_node **stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_node *stack)
{
	rev_rotate(&stack);
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_node *stack)
{
	rev_rotate(&stack);
	rev_rotate(&stack);
	write(1, "rrr\n", 4);	
}
