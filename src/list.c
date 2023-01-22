/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:39:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/22 21:52:37 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

t_stack	*create_node(int nb)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// t_stack	last(t_stack *lst)
// {
// 	while (lst != '\0' && lst->next != '\0')
// 	lst = lst->next;
// 	return (lst);
// }

void	add_to_end(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->prev)
				tmp = tmp->prev;
		tmp->next = new;
		new->prev = tmp;
	}
}


// void create_list(int argc, char **argv, t_stack **stack)
// {
// 	while (argc > 1)
// 	{
// 		add_front(stack, create_node(ft_atolong(argv[1])));
// 		argc--;
// 	}
// }