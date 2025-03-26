/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:18:13 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/25 18:41:45 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_top_a(t_list **stack_a, int nbr, int position)
{
	t_list	*a;
	int		a_len;

	a = *stack_a;
	a_len = ft_lstsize(a);
	a_len++;
	if (nbr < 0)
	{
		put_top_a_bis(stack_a, nbr * -1, position);
		return ;
	}
	while (a)
	{
		a = *stack_a;
		if (a->content == nbr)
			break ;
		else if (position <= a_len / 2)
			rotate(stack_a, 'a');
		else if (position > a_len / 2)
			reverse_rotate(stack_a, 'a');
	}
}

void	put_top_a_bis(t_list **stack_a, int nbr, int position)
{
	t_list	*a;
	t_list	*a_bis;
	int		a_len;

	a = *stack_a;
	a_bis = *stack_a;
	a_len = ft_lstsize(a);
	a_len++;
	while (a)
	{
		a_bis = *stack_a;
		while (a_bis->next)
			a_bis = a_bis->next;
		a = *stack_a;
		if (a_bis->content == nbr)
			break ;
		else if (position <= a_len / 2)
			rotate(stack_a, 'a');
		else if (position > a_len / 2)
			reverse_rotate(stack_a, 'a');
	}
}

void	put_top_b(t_list **stack_b, int nbr, int position)
{
	t_list	*b;
	int		b_len;

	b = *stack_b;
	b_len = ft_lstsize(b);
	while (b->content != nbr && b)
	{
		b = *stack_b;
		if (b->content == nbr)
			break ;
		else if (position <= b_len / 2)
			rotate(stack_b, 'b');
		else if (position > b_len / 2)
			reverse_rotate(stack_b, 'b');
	}
}

int	calcule_goal_bis(t_list **stack_a, int b_target)
{
	t_list	*a;
	int		min;
	int		goal;

	a = *stack_a;
	min = INT_MAX;
	goal = 0;
	while (a)
	{
		if (b_target - a->target < min)
		{
			if (b_target - a->target > 0)
			{
				min = b_target - a->target;
				goal = a->content;
			}
		}
		a = a->next;
	}
	return (goal * -1);
}

int	count_position_bis(t_list **stk, int nbr)
{
	int		i;
	t_list	*stack;

	i = 1;
	stack = *stk;
	while (stack)
	{
		if (stack->target == nbr)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}
