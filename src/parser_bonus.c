/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:56 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/20 11:57:22 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// checks whether there is a '-' or digit
// if not an error appears
// calls atoi to convert a character string to integer value

int	digit_checker(char *str, int *nb)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		if (!str[1])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		error_message();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (!ft_atoi_overflow(str, nb))
		return (0);
	return (1);
}
// A normal atoi does not work due to overflow therefore
// I am using this function that checks whether the minus is
// 1 while it is below 0 which is not possible unless overflow
// also you want to be able to continue with INT_MIN because INT_MAX is one
// higher than INT_MIN and otherwise you won't be able to print it as it
// goes to overflow immediately

int	ft_atoi_overflow(char *str, int *nb)
{
	int	count;
	int	minus;

	*nb = 0;
	count = 0;
	minus = 1;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-')
	{
		minus *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		*nb += str[count] - '0';
		if (*nb < 0 && (*nb != INT_MIN || minus == 1))
			return (0);
		if (str[count + 1] >= '0' && str[count + 1] <= '9')
			*nb *= 10;
		count++;
	}
	*nb *= minus;
	return (1);
}

// parses arguments by checking whether it is a digit or '-'
// then using the atoi_overflow function and at last creating
// a list with nodes

int	parse_args(char **argv, t_stack *stack)
{
	int		i;
	int		nb;

	i = 1;
	while (argv[i])
	{
		if (!digit_checker(argv[i], &nb))
		{
			return (0);
		}
		add_to_end(&(stack->stack_a), create_node(nb));
		i++;
	}
	find_pivot(stack->stack_a, stack->elements_a);
	return (1);
}
