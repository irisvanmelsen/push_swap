/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:38:28 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/17 13:36:34 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

int	main (int argc, char **argv)
{
	t_stack	*stack_a;

	if (argv < 2)
		return (EXIT_FAILURE);
	if (!check_args(argv))
		return (put_error());
	stack_a = fill_list(argc - 1);

}