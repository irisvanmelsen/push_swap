/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:21:23 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/04 15:43:59 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	digit_check(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	space_check(char s)
{
	if ((s >= 9 && s <= 13) || s == 32)
		return (1);
	return (0);
}

int	put_error(void)
{
	write(1, "Error\n", 6);
		return (0);
}

int	ps_atoi(const char *str)
{
	int	count;
	int	minus;
	int	result;

	count = 0;
	minus = 1;
	result = 0;
	while (space_check(str[count]))
		count++;
	if (str[count] == '-' && str[count + 1])
	{
		minus *= -1;
		count++;
	}
	while (str[count])
	{
		if (!digit_check(str[count]))
			return (put_error());
		result *= 10;
		result += str[count] - '0';
		count++;
	}
	result *= minus;
	return (result);
}

int	main (int argc, char **argv)
{	
	if (argc < 2)
		return (0);
	if (!ps_atoi(*argv))
		return (0);
}
