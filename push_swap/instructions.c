/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:15:04 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/27 15:55:14 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	t_list	*lst;
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_3;

	if ((*stack) == NULL || ft_lstsize(*stack) <= 1)
		return ;
	lst = *stack;
	node_1 = lst;
	lst = lst->next;
	node_2 = lst;
	lst = lst->next;
	node_3 = lst;
	node_1->next = node_3;
	node_1->prev = node_2;
	node_2->next = node_1;
	node_2->prev = NULL;
	node_3->prev = node_1;
	*stack = node_2;
	if (c != 'z')
		ft_printf("s%c\n", c);
}

void	rotate(t_list **stack, char c)
{
	t_list	*lst;
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_last;

	if ((*stack) == NULL || ft_lstsize(*stack) <= 1)
		return ;
	lst = *stack;
	node_1 = lst;
	node_2 = lst->next;
	while (lst->next)
		lst = lst->next;
	node_last = lst;
	node_2->prev = NULL;
	node_1->next = NULL;
	node_1->prev = node_last;
	node_last->next = node_1;
	*stack = node_2;
	if (c != 'z')
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list	*lst;
	t_list	*node_1;
	t_list	*node_last2;
	t_list	*node_last;

	if ((*stack) == NULL || ft_lstsize(*stack) <= 1)
		return ;
	lst = *stack;
	node_1 = lst;
	while (lst->next)
		lst = lst->next;
	node_last = lst;
	node_last2 = lst->prev;
	node_last->prev = NULL;
	node_last->next = node_1;
	node_1->prev = node_last;
	node_last2->next = NULL;
	*stack = node_last;
	if (c != 'z')
		ft_printf("rr%c\n", c);
}

void	push(t_list **source, t_list **dest, char c)
{
	t_list	*src;
	t_list	*src1;

	if ((*source) == NULL)
		return ;
	src = *source;
	src1 = src->next;
	if (src->next != NULL)
		src1->prev = NULL;
	ft_lstadd_front(dest, src);
	*source = src1;
	*dest = src;
	ft_printf("p%c\n", c);
}

void	print_stack(t_list **stk, char c)
{
	int	i;
	t_list	*stack;

	i = 1;
	stack = *stk;
	while (stack)
	{
		printf("==================================\n");
		printf("stack %c%d \n", c, i);
		printf("content  ; %ld \n", stack->content);
		printf("target  ; %d \n", stack->target);
		printf("cost  ; %d \n", stack->cost);
		printf("==================================\n");
		stack = stack->next;
		i++;
	}
}
