/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:53:40 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/27 16:57:13 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_tab_int(t_list **stack_a)
{
	int	*tab_of_int;
	int	tab_len;
	int	i;
	t_list	*stack;

	i = 0;
	stack = *stack_a;
	tab_len = ft_lstsize(stack);
	tab_of_int = malloc(sizeof(int) * tab_len);
	if (!tab_of_int)
		return (0);
	while (stack)
	{
		tab_of_int[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (calcule_mediane(tab_of_int, tab_len, stack_a));
}

int	calcule_mediane(int *tab_of_int, int tab_len, t_list **stack_a)
{
	int	i;
	int	j;
	int	tmp;
	int	retour;

	i = 0;
	while (i < tab_len)
	{
		j = 0;
		while (j < tab_len)
		{
			if (tab_of_int[i] < tab_of_int[j])
			{
				tmp = tab_of_int[i];
				tab_of_int[i] = tab_of_int[j];
				tab_of_int[j] = tmp;
			}
			j++;
		}
		i++;
	}
	put_target(stack_a, tab_of_int, tab_len);
	retour = tab_of_int[tab_len / 2];
	return (free(tab_of_int), retour);
}

void	put_target(t_list **stack_a, int *tab_of_int, int tab_len)
{
	int	i;
	t_list *stack;
	
	stack = *stack_a;
	while (stack)
	{
		i = 1;
		while (i <= tab_len)
		{
			if (stack->content == tab_of_int[i - 1])
				stack->target = i;
			i++;
		}
		stack = stack->next;
	}
}

void	push_in_b(t_list **stack_a, t_list **stack_b, int mediane)
{
	int	i;
	int	len_stack;
	t_list	*a;
	
	a = *stack_a;
	i = 0;
	len_stack = ft_lstsize(a);
	while (i < len_stack)
	{
		a = *stack_a;
		if (a->content > mediane)
			push(stack_a, stack_b, 'b');
		else if (a->content < mediane)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
		}
		else if (a->content == mediane)
			rotate(stack_a, 'a');
		a = a->next;
		i++;
	}
}
