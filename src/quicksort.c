/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:57:00 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/02/21 17:38:59 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pivot(t_stack *stack, int total)
{
	t_stack	**sorted;
	t_stack	*tmp;
	int		pivot;
	int		i;

	tmp = stack;
	sorted = malloc(sizeof(t_stack *));
	*sorted = NULL;
	i = 0;
	if (!sorted)
	{
		error_message();
	}
	while (tmp && i <= total)
	{
		add_to_end(sorted, create_node(stack->nb));
		stack = stack->next;
		if (tmp == stack)
			break ;
		i++;
	}
	// printf("check stack:\n");
	// print_stack(stack);
	bubblesort(stack, *sorted);
	// printf("after bubblesort stack:\n");
	// print_stack(stack);
	// printf("after bubblesort sorted:\n");
	// print_stack(*sorted);
	// // printf("after bubblesort index:\n");
	// // print_index(stack);
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
	pivot = find_pivot(*stack_a, total);
	printf("pivot: %d\n", pivot);
	printf("total: %d\n", total);
	while (total - 1 > i)
	{
		// printf("%d, %d\n", tmp->nb, pivot);
		// break ;
		if ((*stack_a)->nb < pivot)
		{
			printf("stack a in quicksort a before push:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort a before push:\n");
			print_stack(*stack_b);
			printf("------------------\n");
			pb(stack_a, stack_b);
			printf("stack a in quicksort a after push:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort a after push:\n");
			print_stack(*stack_b);
			counter++;
		}
		else
		{
			printf("stack a in quicksort a before rotate:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort a before rotate:\n");
			print_stack(*stack_b);
			ra(stack_a);
			printf("stack a in quicksort a after rotate:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort a after rotate:\n");
			print_stack(*stack_b);
		}
		i++;
	}
	while (total > i - counter)
	{
		rra(stack_a);
		i++;
	}
	quicksort_a(stack_a, stack_b, total - counter);
	printf("stack a before quicksort b:\n");
	print_stack(*stack_a);
	quicksort_b(stack_a, stack_b, total);
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
		return (push_a(*stack_a, *stack_b, total));
	pivot = find_pivot(*stack_b, total);
	while (i < total - 1)
	{
		if ((*stack_b)->nb < pivot)
		{
			printf("stack a in quicksort b before push:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort b before push:\n");
			print_stack(*stack_b);
			printf("------------------\n");
			pa(stack_b, stack_a);
			printf("stack a in quicksort b after push:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort b after push:\n");
			print_stack(*stack_b);
			counter++;
		}
		else
		{
			printf("stack a in quicksort b before rotate:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort b before rotate:\n");
			print_stack(*stack_b);
			rb(stack_b);
			printf("stack a in quicksort b after rotate:\n");
			print_stack(*stack_a);
			printf("------------------\n");
			printf("stack b in quicksort b after rotate:\n");
			print_stack(*stack_b);
		}
		i++;
	}
	while (total > i - counter)
	{
		rrb(stack_b);
		i++;
	}
	quicksort_a(stack_a, stack_b, total);
	quicksort_b(stack_b, stack_a, total - counter);
}