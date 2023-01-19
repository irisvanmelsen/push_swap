/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:39:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/19 18:35:54 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

t_stack	*create_node(int nb)
{
	t_stack *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node = NULL;
	node->nb = nb;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	add_front(t_stack **lst, t_stack *new)
{
	if (lst != '\0' && new != '\0')
	{
		new->next = *lst;
		*lst = new;
	}
}

void create_list(int argc, char **argv, t_stack **stack)
{
	while (argc > 1)
	{
		add_front(stack, create_node(ft_atolong(argv[1])));
		argc--;
	}
}