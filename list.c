/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:39:29 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/11 14:27:39 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

t_stack	create_list(int nb)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	return (node);
}

void	fill_list(int nb)
{
	t_stack *tmp;

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_list(int b);
}