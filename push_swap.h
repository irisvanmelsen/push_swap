/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:51:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/23 18:15:20 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*create_node(int nb);
int		digit_checker(char *str, int *nb, t_stack **stack_a);
char	*ps_checker(t_stack *lst, char **argv);
int		check_args(char **argv, t_stack **stack_a);
t_stack	*create_node(int nb);
int		parse_args(t_stack **stack_a, int *nb);
int		ft_atoi_overflow(char *str, int *nb);
void	add_to_end(t_stack **lst, t_stack *new);
int		arg_checker(int argc, char **argv);

#endif