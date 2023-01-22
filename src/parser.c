/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:56 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/21 17:52:42 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../push_swap.h"

int	digit_checker(char *str)
{
	int	i;

	i = 0;
	long k;
	if (str[0] == '-')
	{
		if (!str[1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
			else 
				return (0);
	}
	k = ft_atolong(str);
	if (k > 2147483647 || k < -2147483648)
		return(0);
	return (1);
}

int	ft_atolong(char *str)
{
	int	count;
	int	minus;
	int	result;

	count = 0;
	minus = 1;
	result = 0;
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

int	parse_args(char **str, t_stack **stack_a)
{
	while (*str)
	{
		add_to_end(stack_a, create_node(ft_atolong(*str)));
		str++;
	}
	return (1);
}

int	check_args(char **argv, t_stack **stack_a)
{
	char **amount;
	int	i;
	
	i = 1;
	while (*argv)
	{
		if (!digit_checker(*argv))
		{
			printf("%s", "Hello");
			write(1, "Error\n", 6);
			return (0);
		}
		amount = ft_split(*argv, ' ');
		if (!amount)
			write(1, "Error\n", 6);
		if (!parse_args(amount, stack_a))
		{
			free(amount);
			return(0);
		}
	free(amount);
	argv++;
	}
	return (1);
}