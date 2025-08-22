/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinliang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:08:32 by jinliang          #+#    #+#             */
/*   Updated: 2025/08/22 17:05:40 by jinliang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				in_lis;
	struct s_stack	*next;
}				t_stack;

typedef struct s_lis
{
	int	*indices;
	int	*len;
	int	*prev;
	int	*look;
	int	size;
}		t_lis;

/* Stack Operations */
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **from, t_stack **to);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Stack Initialization */
int		is_valid_number(char *s);
int		is_duplicates(t_stack *stack, int value);
void	append_node(t_stack	**stack, int value);
void	assign_indices(t_stack *stack);
t_stack	*init_stack(t_stack **stack, char **numb, int count);

/* LIS flagging */
void	fill_indices_array(t_stack *stack, t_lis *lis);
void	compute_lis_arrays(t_lis *lis);
void	mark_from_lookup(t_stack *stack, t_lis *lis);
void	get_lis_flags(t_stack *a, int n);

/* Utilities */
void	ft_error(void);
void	free_stack(t_stack **stack);
void	free_all_and_error(t_stack **stack, char **numb, int count);
void	free_split(char **split);
int		is_sorted(t_stack *stack);

/* Cost & Target Calculation */
int		rotation_cost(t_stack *stack, int target_pos);
int		find_target_position(t_stack *stack, int index);
int		get_position(t_stack *stack, int index);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);

/* Small Sort (≤ 5 numbers) */
int		stack_size(t_stack *stack);
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b, int size);
void	sort_small(t_stack **a, t_stack **b, int size);

// /* Greedy Chunks Sort */
void	push_to_b(t_stack **a, t_stack **b, int size);
void	update_chunk_range(int *chunk_start, int *chunk_end,
			int chunk_size, int size);
void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk_count, int size);
void	do_rotate(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	push_back_to_a(t_stack **a, t_stack **b);

/* Main Dispatcher */
void	sort_stack(t_stack **a, t_stack **b);
int		calc_cost(t_stack *a, t_stack *b, int idx);
t_stack	*find_cheapest_node(t_stack *a, t_stack *b);
void	final_rotate(t_stack **a, int size);

/* MY CHECKER */
int		apply_instruction(t_stack **a, t_stack **b, char *op);
int		stack_size(t_stack *stack);

#endif