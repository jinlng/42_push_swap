/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:27:01 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/21 15:51:33 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	is_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	append_node(t_stack	**stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	assign_indices(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;
	int		index;
	int		size;

	size = stack_size(stack);
	index = 0;
	while (index < size)
	{
		current = stack;
		min = NULL;
		while (current)
		{
			if (current->index == -1 && (!min || current->value < min->value))
				min = current;
			current = current->next;
		}
		if (min)
			min->index = index++;
	}
}

t_stack	*init_stack(t_stack **stack, char **numb, int count)
{
	int		i;
	long	value;

	if (!numb || !stack)
		return (NULL);
	i = -1;
	while (++i < count || (count == 0 && numb[i] != NULL))
	{
		if (!is_valid_number(numb[i]))
			free_all_and_error(stack, numb, count);
		value = ft_atol(numb[i]);
		if (value < INT_MIN || value > INT_MAX)
			free_all_and_error(stack, numb, count);
		if (is_duplicates(*stack, (int)value))
			free_all_and_error(stack, numb, count);
		append_node(stack, value);
	}
	assign_indices(*stack);
	return (*stack);
}
