/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:19 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 14:02:18 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_node **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

// void	rotate_both(t_node **stack)
// {
// 	rotate(stack->stack_a);
// 	rotate(stack->stack_b);
// 	write(1, "rr\n", 3);
// }
