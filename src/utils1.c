/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:52 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/01/31 18:15:15 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// tmp is a temporary of stack so it can be adjusted
// int swap is a counter that keeps track of whether
// a swap happened or not

void	bubblesort(t_stack **stack)
{
	t_stack	*tmp;
	int		swap;

	tmp = *stack;
	if (!tmp)
		return ;
	swap = 1;
	while (swap != 0)
	{
		swap = 0;
		bs_sort(tmp, &swap, *stack);
	}
}

// tmp is used as a starting point of sorting process
// swap keeps track of whether a swap happened or not
// function starts with initializing pointer last to stack
// and moving it to the last node before tmp (start)
// then tmp continues to sort up until the end (last)
// has been reached
// if there is only one number / node then tmp->next = stack
// in this case last is updated to be equal to tmp

void	bs_sort(t_stack *tmp, int *swap, t_stack *stack)
{
	t_stack	*last;
	int		error;

	last = stack;
	error = 0;
	while (last->next != tmp)
		last = last->next;
	while (tmp != last)
	{
		if (tmp->nb == tmp->next->nb && error == 0)
		{
			write(1, "Error\n", 6);
			error = 1;
			exit(0);
		}
		if (tmp->nb > tmp->next->nb)
		{
			bs_swap(tmp, tmp->next);
			*swap = 1;
		}
		tmp = tmp->next;
		if (tmp->next == stack)
			last = tmp;
	}
}

// uses a tmp to swap the value of stack1 and stack2

void	bs_swap(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	tmp = stack1->nb;
	stack1->nb = stack2->nb;
	stack2->nb = tmp;
}

// test function which prints the stack

// void	print_stack(t_stack *stack)
// {
// 	t_stack	*start;

// 	if (!stack)
// 		return ;
// 	start = stack;
// 	while (stack)
// 	{
// 		printf("output: %d\n", stack->nb);
// 		stack = stack->next;
// 		if (stack == start)
// 			break ;
// 	}
// }