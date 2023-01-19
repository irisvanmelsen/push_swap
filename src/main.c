/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/19 18:39:55 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../push_swap.h"

int	main (int argc, char **argv)
{
	t_stack	*stack;

	stack = 0;
	if (argc < 2)
		return (EXIT_SUCCESS);
	argv = parse_args(argv, argc);
	create_list(argc, argv, &stack);
	return (0);
}