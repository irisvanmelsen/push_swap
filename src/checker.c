/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:27:18 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/17 18:28:12 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../push_swap.h"

// void	put_error(void)
// {
// 	write(1, "Error\n", 6);
// 		exit (EXIT_FAILURE);
// }

int	digit_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '-' && str[i + 1])
				return (1);
			return (0);
		}
	i++;
	}
	return (1);
}

char *ps_checker(t_stack *lst, char **argv)
{
	if (lst == NULL)
		write(1, "Error\n", 6);
	while (lst != NULL)
	{
		if (!digit_checker(*argv))
			write(1, "Error\n", 6);
	}
	return(0);
}

char	*check_args(char **argv, int argc, t_stack *stack_a)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		write(1, "Error\n", 6);
	if (!ps_checker(stack_a, argv))
		return (NULL);
	return (0);
}