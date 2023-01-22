/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:51:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/21 17:52:38 by iris             ###   ########.fr       */
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
	struct s_stack	*prev;
}	t_stack;

t_stack	*create_node(int nb);
int		digit_checker(char *str);
char	*ps_checker(t_stack *lst, char **argv);
int		check_args(char **argv, t_stack **stack_a);
t_stack	*create_node(int nb);
int		parse_args(char **str, t_stack **stack_a);
int		ft_atolong(char *str);
void	add_to_end(t_stack **lst, t_stack *new);
int		arg_checker(int argc, char **argv);
t_stack	last(t_stack *lst);

#endif