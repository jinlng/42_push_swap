/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:51:30 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/21 21:22:16 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		init_stack(&a, ft_split(av[1], ' '), 0);
	else
		init_stack(&a, av + 1, ac - 1);
	line = get_next_line(0);
	while (line)
	{
		if (!apply_instruction(&a, &b, line))
			return (free(line), free_stack(&a), free_stack(&b), ft_error(), 0);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&a), free_stack(&b), 0);
}

int	apply_instruction(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(a);
	else if (!ft_strcmp(op, "sb\n"))
		sb(b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(op, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(op, "ra\n"))
		ra(a);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(op, "rra\n"))
		rra(a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b);
	else
		return (ft_error(), 0);
	return (1);
}

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
