/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:00:36 by joseph            #+#    #+#             */
/*   Updated: 2024/09/26 12:54:32 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sort(t_list **stack_a, t_list **stack_b)
{
	int		is_sort;
	int		a_len;
	int		target_position;
	t_list	*a;

	a = *stack_a;
	is_sort = 0;
	while (is_sort == 0)
		is_sort = sort(stack_a, stack_b);
	target_position = count_position_bis(stack_a, 1);
	a = *stack_a;
	a_len = ft_lstsize(a);
	while (a->target != 1)
	{
		if (target_position <= a_len / 2)
			rotate(stack_a, 'a');
		if (target_position > a_len / 2)
			reverse_rotate(stack_a, 'a');
		a = *stack_a;
	}
	return (is_sort);
}

int	sort(t_list **stack_a, t_list **stack_b)
{
	int		moins_couteux;
	t_list	*b;

	b = *stack_b;
	if (b == NULL)
		return (1);
	put_cout(stack_a, stack_b);
	moins_couteux = less_price(stack_a, stack_b);
	put_top_b(stack_b, moins_couteux, count_position(stack_b, moins_couteux));
	b = *stack_b;
	put_top_a(stack_a, b->goal, count_position(stack_a, b->goal));
	push(stack_b, stack_a, 'a');
	return (0);
}

int	less_price(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	int		min;
	int		nbr;

	b = *stack_b;
	min = INT_MAX;
	put_cout(stack_a, stack_b);
	while (b)
	{
		if (b->cost < min)
		{
			min = b->cost;
			nbr = b->content;
		}
		b = b->next;
	}
	return (nbr);
}

void	tiny_sort(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a < b && b < c && a < c)
		return ;
	if (a > c && a > b && c > b)
		rotate(stack_a, 'a');
	if (b > a && a > c && b > c)
		reverse_rotate(stack_a, 'a');
	if (a > b && c > a && c > b)
		swap(stack_a, 'a');
	if (a > b && b > c && a > c)
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	if (b > c && b > c && c > a)
	{
		reverse_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

int	check_ordre(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	while (a->next)
	{
		if (a->target + 1 != a->next->target)
			return (1);
		a = a->next;
	}
	return (0);
}
