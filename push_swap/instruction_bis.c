/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:14:52 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/19 16:14:12 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 'z');
	swap(stack_b, 'z');
	ft_printf("ss\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'z');
	rotate(stack_b, 'z');
	ft_printf("rr\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'z');
	reverse_rotate(stack_b, 'z');
	ft_printf("rrr\n");
}
