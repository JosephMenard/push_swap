/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:22:15 by joseph            #+#    #+#             */
/*   Updated: 2024/09/27 11:24:55 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_cout(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*a;

	b = *stack_b;
	a = *stack_a;
	put_goal(stack_a, stack_b);
	while (b)
	{
		b->cost = calcule_cout(stack_a, stack_b, b->goal, b->content);
		b = b->next;
	}
}

int	calcule_cout(t_list **stack_a, t_list **stack_b, int goal, int nbr)
{
	int		count;
	int		b_len;

	count = 0;
	b_len = ft_lstsize(*stack_b);
	count += count_position(stack_b, nbr);
	if (count >= b_len / 2)
		count = b_len - count;
	if (goal < 0)
	{
		goal = goal * -1;
		count++;
	}
	return (count + calcule_cout_bis(stack_a, goal));
}

int	count_position(t_list **stk, int nbr)
{
	int		i;
	t_list	*stack;

	i = 1;
	stack = *stk;
	while (stack)
	{
		if (stack->content == nbr)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

void	put_goal(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	int		goal;

	b = *stack_b;
	while (b)
	{
		goal = calcule_goal(stack_a, b->target);
		if (goal == 0)
		goal = calcule_goal_bis(stack_a, b->target);
		b->goal = goal;
		b = b->next;
	}
}

int	calcule_goal(t_list **stack_a, int b_target)
{
	t_list	*a;
	int		min;
	int		goal;

	a = *stack_a;
	min = INT_MAX;
	goal = 0;
	while (a)
	{
		if (a->target - b_target < min)
		{
			if (a->target - b_target > 0)
			{
				min = a->target - b_target;
				goal = a->content;
			}
		}
		a = a->next;
	}
	return (goal);
}
