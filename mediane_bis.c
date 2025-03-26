/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:26:26 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/25 15:49:58 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_b(t_list **stack_a, t_list **stack_b, int mediane)
{
	int		len_stack;
	int		i;
	t_list	*a;

	a = *stack_a;
	i = 0;
	len_stack = ft_lstsize(a);
	while (i < len_stack)
	{
		a = *stack_a;
		if (a->content > mediane * 1.25)
			push(stack_a, stack_b, 'b');
		else if (a->content < mediane * 1.25 && a->content > mediane)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
		}
		else if (a->content == mediane || a->content < mediane)
			rotate(stack_a, 'a');
		i++;
	}
	push_in_bis(stack_a, stack_b, mediane);
}

void	push_in_bis(t_list **stack_a, t_list **stack_b, int mediane)
{
	int		len_stack;
	int		i;
	t_list	*a;

	a = *stack_a;
	i = 0;
	len_stack = ft_lstsize(a);
	while (i++ < len_stack)
	{
		a = *stack_a;
		if (a->content == mediane)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
		}
		else
			rotate(stack_a, 'a');
	}
	push_in_bis_bis(stack_a, stack_b, mediane);
}

void	push_in_bis_bis(t_list **stack_a, t_list **stack_b, int mediane)
{
	int		len_stack;
	int		i;
	t_list	*a;

	a = *stack_a;
	i = 0;
	len_stack = ft_lstsize(a);
	while (i < len_stack)
	{
		a = *stack_a;
		if (a->content < mediane && a->content > mediane * 0.75)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	bis_bis_bis(stack_a, stack_b);
}

void	bis_bis_bis(t_list **stack_a, t_list **stack_b)
{
	int		len_stack;
	t_list	*a;

	a = *stack_a;
	len_stack = ft_lstsize(a);
	while (len_stack != 3)
	{
		a = *stack_a;
		push(stack_a, stack_b, 'b');
		rotate(stack_b, 'b');
		len_stack--;
	}
}
