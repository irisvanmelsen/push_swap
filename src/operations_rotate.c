/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:19 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/15 12:57:17 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// function that rotates in stack_a

void	rotate_a(t_node **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

// function that rotates in stack_b

void	rotate_b(t_node **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}
