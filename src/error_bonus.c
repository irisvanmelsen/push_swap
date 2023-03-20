/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:42:56 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/03/17 15:12:30 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void function that writes Error

void	error_message(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
