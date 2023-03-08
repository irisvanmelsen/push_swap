/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:56 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/08 20:53:09 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
// I am using this function.

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

int	parse_args(char **argv, int argc, t_stack *stack)
{
	char	**amount;
	int		i;
	int		nb;
	// int		counter;

	i = 1;
	// counter = 0;
	amount = argv;
	amount = ft_split(argv[i], ' ');
	while (argc )
	while (argv[i])
	{
		if (!digit_checker(amount[i], &nb))
			return (0);
		// printf("address stack->stack_a: %p\n", (&(stack->stack_a));
		// printf("address &stack->stack_a: %d\n", *(stack->stack_a));
		add_to_end(&(stack->stack_a), create_node(nb));
		free(amount[i]);
		i++;
	}
	free (amount);
	return (1);
}

char split_all(int argc, char **argv)
{
	int i;
	char **args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		i++;
	}
}