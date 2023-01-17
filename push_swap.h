/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:51:22 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/17 14:03:21 by ivan-mel         ###   ########.fr       */
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
	struct s_list	*next;
	struct s_list	*previous;
}	t_stack;

t_stack	create_node(int nb);
t_stack	fill_list(int nb);
void	put_error();
int		digit_checker(char *str);
int		ps_checker(t_list lst);
void	check_args(char **argv);


#endif