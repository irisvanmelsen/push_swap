/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:51:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/19 18:40:01 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

t_stack	*create_node(int nb);
int		digit_checker(char *str);
char	*ps_checker(t_stack *lst, char **argv);
char	**parse_args(char **argv, int argc);
t_stack	*create_node(int nb);
void 	create_list(int argc, char **argv, t_stack **stack);
int		ft_atolong(const char *str);
void	add_front(t_stack **lst, t_stack *new);

#endif