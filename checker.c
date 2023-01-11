/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:21:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/11 11:47:40 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	put_error()
{
	write(1, "Error\n", 6);
		exit (EXIT_FAILURE);
}

int	char_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i))
		{
			if (str[i] str[i] == '-' && str[i + 1])
				return (1);
			if (str[i] str[i] == '+' && str[i + 1])
				return (1);
		return (0);
		}
	i++;
	}
	return (0);
}

int ps_checker(t_list lst)
{
	while (lst != NULL)
	{
		if (!char_checker(argv))
			return (EXIT_FAILURE);
		if	(!dup_checker(argv))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
}

void check_argv(char **argv)
{
	argv = ft_split(argv[0], ' ');
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!ps_checker(argv))
		return (EXIT_FAILURE);
}

int	main (int argc, char **argv)
{	

}