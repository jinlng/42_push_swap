/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:05:15 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/19 17:16:21 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_cost(t_stack *stack, int target_pos)
{
	int	size;

	size = stack_size(stack);
	if (target_pos <= size / 2)
		return (target_pos);
	else
		return (target_pos - size);
}

int	find_target_position(t_stack *a, int index)
{
	t_stack	*current;
	int		pos;
	int		size;
	int		min_index;
	int		max_index;

	if (!a)
		return (0);
	size = stack_size(a);
	min_index = find_min_index(a);
	max_index = find_max_index(a);
	if (index < min_index)
		return (get_position(a, min_index));
	if (index > max_index)
		return (get_position(a, max_index) + 1);
	current = a;
	pos = 0;
	while (current->next)
	{
		if (current->index < index && index < current->next->index)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (0);
}

int	get_position(t_stack *stack, int index)
{
	t_stack	*current;
	int		position;

	if (!stack)
		ft_error();
	current = stack;
	position = 0;
	while (current)
	{
		if (current->index == index)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	find_min_index(t_stack *stack)
{
	int	min_index;

	if (!stack)
		ft_error();
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

int	find_max_index(t_stack *stack)
{
	int	max_index;

	if (!stack)
		ft_error();
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}
