/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:56 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/19 18:43:34 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../push_swap.h"

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

int	ft_atolong(const char *str)
{
	int	count;
	int	minus;
	int	result;

	count = 0;
	minus = 1;
	result = 0;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-')
	{
		minus *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		result *= 10;
		result += str[count] - '0';
		count++;
	}
	result *= minus;
	return (result);
}

// char *ps_checker(t_stack *lst, char **argv)
// {
// 	if (lst == NULL)
// 		write(1, "Error\n", 6);
// 	while (lst != NULL)
// 	{
// 		if (!digit_checker(*argv))
// 			write(1, "Error\n", 6);
// 	}
// 	return(0);
// }

char	**parse_args(char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		write(1, "Error\n", 6);
	if (digit_checker(*argv) == 0)
		write(1, "Error\n", 6);
	return (argv);
}