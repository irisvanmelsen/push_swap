/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/17 17:31:16 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include "../push_swap.h"

int	main (int argc, char **argv)
{
	t_stack	*stack_a;

	if (argv < 2)
		return (EXIT_FAILURE);
	argv = check_args(argv, argc);
	fill_list(argc - 1);
	return (0);
}