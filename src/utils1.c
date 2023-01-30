/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:52 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/30 18:04:44 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// tmp = tmp->next is done so you always start at
// the beginning for each iteration

void	bubblesort(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*loop;

	tmp = *stack;
	if (!tmp)
		return ;
	loop->next = tmp;
	while (tmp->next != tmp)
	{
		if (tmp->nb == tmp->next->nb)
			write(1, "Error\n", 6);
		if (tmp->nb > tmp->next->nb)
		{
			bs_swap(tmp, tmp->next);
		}
		tmp = tmp->next;
	}
	tmp = loop->next;
}

void	bs_swap(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	tmp = stack1->nb;
	stack1->nb = stack2->nb;
	stack2->nb = tmp;
}