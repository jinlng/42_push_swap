/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:54:27 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/21 21:23:33 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	sort_2(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	final_rotate(a, size);
	pb(a, b);
	if (size == 5)
	{
		final_rotate(a, 4);
		pb(a, b);
	}
	sort_3(a);
	if (size == 5 && *b && (*b)->next && (*b)->index < (*b)->next->index)
		sb(b);
	while (*b)
		pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b, size);
}
