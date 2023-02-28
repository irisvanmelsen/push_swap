/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:39:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/28 14:53:48 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index = 0;
	node->sort = 0;
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_to_end(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != *lst)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = *lst;
		(*lst)->prev = new;
	}
}