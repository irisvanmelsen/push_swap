/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:39:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/14 20:52:33 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(int nb)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_to_end(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!lst)
		return ;
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

size_t	list_size(t_node *stack)
{
	size_t	size;
	t_node	*home;

	if (!stack)
		return (0);
	size = 1;
	home = stack;
	stack = stack->next;
	while (stack != home)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	is_sorted(t_node *stack)
{
	t_node	*last_a;

	last_a = stack->prev;
	while (stack != last_a)
	{
		if (stack->nb > stack->next->nb)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

void	free_lst(t_node *list)
{
	t_node	*tmp;
	t_node	*end;

	if (!list)
		return ;
	end = list->prev;
	while (list != end)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
}
