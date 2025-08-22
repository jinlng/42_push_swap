/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:22:16 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/21 18:32:53 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**num;

	a = NULL;
	b = NULL;
	if (ac == 2)
	{
		num = ft_split(av[1], ' ');
		init_stack(&a, num, 0);
		free_split(num);
	}
	else if (ac > 2)
	{
		num = av + 1;
		init_stack(&a, num, ac - 1);
	}
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size <= 5)
		sort_small(a, b, size);
	else
	{
		if (size < 500)
		{
			get_lis_flags(*a, size);
			push_to_b(a, b, size);
		}
		else
			push_chunks_to_b(a, b, 7, size);
		push_back_to_a(a, b);
		final_rotate(a, size);
	}
}

int	calc_cost(t_stack *a, t_stack *b, int idx)
{
	int	current_cost;
	int	cost_a;
	int	cost_b;

	cost_a = rotation_cost(a, find_target_position(a, idx));
	cost_b = rotation_cost(b, get_position(b, idx));
	current_cost = ft_abs(cost_a) + ft_abs(cost_b)
		- ft_min(ft_abs(cost_a), ft_abs(cost_b));
	return (current_cost);
}

t_stack	*find_cheapest_node(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_cost;
	int		current_cost;

	current = b;
	cheapest = b;
	min_cost = INT_MAX;
	while (current)
	{
		current_cost = calc_cost(a, b, current->index);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

void	final_rotate(t_stack **a, int size)
{
	int	min_pos;

	min_pos = get_position(*a, find_min_index(*a));
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < size)
			rra(a);
	}
}
