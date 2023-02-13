/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/13 16:55:09 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pivot(t_stack *stack)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	**sorted;

	bubblesort(stack);
	one = stack;
	two = stack;
	sorted = malloc(sizeof(t_stack *));
	*sorted = NULL;
	if (!sorted)
		error_message();
	while (one)
	{
		add_to_end(sorted, create_node(stack->nb));
		stack = stack->next;
		if (one == stack)
			break ;
	}
	printf("sorted stack:\n");
	print_stack(*sorted);
	while (two && two->next != stack)
	{
		if (two->next->next == stack)
			break ;
		one = one->next;
		two = two->next->next;
	}
	printf("pivot: %d\n", one->nb);
	printf("index: %d\n", stack->index);
	free(sorted);
	return (one->nb);
}

// void	algorithm(t_stack **stack_a, t_stack **stack_b, int total)
// {
// 	quicksort_a(stack_a, stack_b);
// }

// pb: take the first element at the top of a and put it at the top of b.
// ra: shift up all elements of stack a by 1, the first element
// becomes the last one.

void	quicksort_a(t_stack **stack_a, t_stack **stack_b, int total)
{
	t_stack	*tmp;
	int		pivot;
	int		old_total;
	int		counter;

	old_total = total;
	counter = 0;
	tmp = *stack_a;
	pivot = find_pivot(*stack_a);
	if (check_a(*stack_a, total) == 1)
		return ;
	if (tmp->nb < pivot)
	{
		pb(stack_a, stack_b);
		counter++;
		// tmp = tmp->next;
	}
	else
		ra(stack_a);
	// tmp = tmp->next;
	quicksort_a(stack_a, stack_b, total - counter);
	quicksort_b(stack_b, stack_a, total);
}

void	quicksort_b(t_stack **stack_a, t_stack **stack_b, int total)
{
	t_stack	*tmp;
	int		pivot;
	int		old_total;
	int		counter;

	old_total = total;
	counter = 0;
	tmp = *stack_b;
	pivot = find_pivot(*stack_b);
	if (check_b(*stack_a, total) == 1)
		return ;
	if (tmp->nb < pivot)
	{
		pa(stack_b, stack_a);
		counter++;
	}
	else
		rb(stack_b);
	quicksort_a(stack_a, stack_b, total);
	quicksort_b(stack_b, stack_a, total - counter);
}