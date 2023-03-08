/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:39:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/08 15:56:13 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(int nb)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	// stack->index = 0;
	// stack->sort = 0;
	// stack->elements_b = 0;
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_to_end(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!*lst)
	{
		*lst = new;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
	}
	else
	{
		tmp = *lst;
	printf("tmp->nb: %d\n", tmp->nb);
		while (tmp->next != *lst)
		{
			printf("tmp->nb: %d\n", tmp->nb);
			tmp = tmp->next;
		}
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

// t_stack *list_take_node(t_stack stack)
// {
// 	(void) stack;
// 	return (NULL);
// }

// t_stack *list_add_node_front(t_stack *node, t_stack stack)
// {
// 	(void) stack;
// 	(void) node;
// 	return (NULL);
// }
