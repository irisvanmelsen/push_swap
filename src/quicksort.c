/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/15 17:29:45 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pivot(t_stack *stack)
{
	t_stack	**sorted;
	t_stack	*tmp;
	int		pivot;

	tmp = stack;
	sorted = malloc(sizeof(t_stack *));
	*sorted = NULL;
	if (!sorted)
		error_message();
	while (tmp)
	{
		add_to_end(sorted, create_node(stack->nb));
		stack = stack->next;
		if (tmp == stack)
			break ;
	}
	printf("check stack:\n");
	print_stack(stack);
	bubblesort(stack, *sorted);
	// printf("after bubblesort stack:\n");
	// print_stack(stack);
	// printf("after bubblesort sorted:\n");
	// print_stack(*sorted);
	// printf("after bubblesort index:\n");
	// print_index(stack);
	pivot = find_middle(*sorted);
	// printf("pivot: %d\n", tmp->nb);
	free(sorted);
	return (pivot);
}

int	find_middle(t_stack *stack)
{
	t_stack	*one;
	t_stack	*two;

	one = stack;
	two = stack;
	while (two && two->next != stack)
	{
		if (two->next->next == stack)
			break ;
		one = one->next;
		two = two->next->next;
	}
	return (one->nb);
}

// pb: take the first element at the top of a and put it at the top of b.
// ra: shift up all elements of stack a by 1, the first element
// becomes the last one.

void	quicksort_a(t_stack **stack_a, t_stack **stack_b, int total)
{
	t_stack	*tmp;
	int		i;
	int		pivot;
	int		old_total;
	int		counter;

	i = 0;
	old_total = total;
	counter = 0;
	tmp = *stack_a;
	if (check_a(*stack_a, total) == 1)
		return ;
	pivot = find_pivot(*stack_a);
	printf("pivot: %d\n", pivot);
	while (total - 1 > i)
	{
		// printf("%d, %d\n", tmp->nb, pivot);
		// break ;
		if ((*stack_a)->nb < pivot)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
		i++;
	}
	// while (total > i - counter && )
	// printf("stack b:\n");
	// print_stack(*stack_b);
	quicksort_a(stack_a, stack_b, total - counter);
	quicksort_b(stack_b, stack_a, total);
}

void	quicksort_b(t_stack **stack_a, t_stack **stack_b, int total)
{
	t_stack	*tmp;
	int		i;
	int		pivot;
	int		old_total;
	int		counter;

	i = 0;
	old_total = total;
	counter = 0;
	tmp = *stack_b;
	if (check_b(*stack_a, total) == 1)
		return ;
	pivot = find_pivot(*stack_b);
	while (i < total - 1)
	{
		if ((*stack_b)->nb < pivot)
		{
			pa(stack_b, stack_a);
			counter++;
		}
		else
			rb(stack_b);
		i++;
	}
	quicksort_a(stack_a, stack_b, total);
	quicksort_b(stack_b, stack_a, total - counter);
}