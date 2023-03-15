/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:11 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 12:57:13 by ivan-mel         ###   ########.fr       */
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
