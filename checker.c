/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:21:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/17 13:08:01 by ivan-mel         ###   ########.fr       */
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

int	digit_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i))
		{
			if (str[i] str[i] == '-' && str[i + 1])
				return (1);
		return (0);
		}
	i++;
	}
	return (1);
}

int ps_checker(t_list lst)
{
	if (lst == NULL)
		return (put_error());
	while (lst != NULL)
	{
		if (!digit_checker(argv))
			return (put_error());
	}
}

void check_args(char **argv)
{
	if (argv == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		return (NULL);
	if (!ps_checker(argv))
		return (NULL);
}