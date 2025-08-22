/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:55:46 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/21 15:37:34 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*a)->in_lis)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

void	update_chunk_range(int *chunk_start, int *chunk_end,
		int chunk_size, int size)
{
	*chunk_start = *chunk_end + 1;
	*chunk_end += chunk_size;
	if (*chunk_end >= size)
		*chunk_end = size - 1;
}

void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk_count, int size)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	chunk_size = (size + chunk_count - 1) / chunk_count;
	chunk_start = 0;
	chunk_end = chunk_size - 1;
	while (*a)
	{
		if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
		{
			pb(a, b);
			if (*b && (*b)->next && (*b)->index < (*b)->next->index)
				sb(b);
		}
		else
			ra(a);
		if (stack_size(*b) > chunk_end && chunk_end + 1 < size)
			update_chunk_range(&chunk_start, &chunk_end, chunk_size, size);
	}
}

void	do_rotate(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_a--)
		ra(a);
	while (cost_a < 0 && cost_a++)
		rra(a);
	while (cost_b > 0 && cost_b--)
		rb(b);
	while (cost_b < 0 && cost_b++)
		rrb(b);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int		cost_a;
	int		cost_b;
	t_stack	*best;

	while (*b)
	{
		best = find_cheapest_node(*a, *b);
		cost_a = rotation_cost(*a, find_target_position(*a, best->index));
		cost_b = rotation_cost(*b, get_position(*b, best->index));
		do_rotate(a, b, cost_a, cost_b);
		pa(a, b);
	}
}
