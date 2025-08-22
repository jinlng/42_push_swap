/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:43:45 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/22 16:56:27 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_indices_array(t_stack *stack, t_lis *lis)
{
	t_stack	*cur;
	int		i;

	cur = stack;
	i = 0;
	while (cur && i < lis->size)
	{
		lis->indices[i] = cur->index;
		lis->len[i] = 1;
		lis->prev[i] = -1;
		lis->look[i] = 0;
		cur = cur->next;
		i++;
	}
}

void	compute_lis_arrays(t_lis *lis)
{
	int	i;
	int	j;

	i = 1;
	while (i < lis->size)
	{
		j = 0;
		while (j < i)
		{
			if (lis->indices[j] < lis->indices[i]
				&& lis->len[j] + 1 > lis->len[i])
			{
				lis->len[i] = lis->len[j] + 1;
				lis->prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	mark_from_lookup(t_stack *stack, t_lis *lis)
{
	int		i;
	int		end;
	t_stack	*cur;

	i = 1;
	end = 0;
	while (i < lis->size)
	{
		if (lis->len[i] > lis->len[end])
			end = i;
		i++;
	}
	while (end != -1)
	{
		lis->look[lis->indices[end]] = 1;
		end = lis->prev[end];
	}
	cur = stack;
	while (cur)
	{
		cur->in_lis = lis->look[cur->index];
		cur = cur->next;
	}
}

void	get_lis_flags(t_stack *a, int n)
{
	t_lis	lis;

	lis.size = n;
	lis.indices = malloc(sizeof(int) * n);
	lis.len = malloc(sizeof(int) * n);
	lis.prev = malloc(sizeof(int) * n);
	lis.look = malloc(sizeof(int) * n);
	if (!lis.indices || !lis.len || !lis.prev || !lis.look)
		ft_error();
	fill_indices_array(a, &lis);
	compute_lis_arrays(&lis);
	mark_from_lookup(a, &lis);
	free(lis.indices);
	free(lis.len);
	free(lis.prev);
	free(lis.look);
}
