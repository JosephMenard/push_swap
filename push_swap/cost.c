/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:22:15 by joseph            #+#    #+#             */
/*   Updated: 2024/07/29 13:21:09 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    put_cout(t_list **stack_a, t_list **stack_b)
{
    t_list  *b;
    t_list  *a;
    
    b = *stack_b;
    a = *stack_a;
    while (b)
    {
        a = *stack_a;
        b->cost = calcule_cout(&a, stack_b, b->target, b->content);
        while (b->cost == 0 && a->next != NULL)
        {
            a = a->next;
            b->cost = calcule_cout(&a, stack_b, b->target, b->content);
        }
        //printf("cout ; %d\n nbr  ; %ld\n", b->cost, b->content);
        b = b->next;
    }
}

int   calcule_cout(t_list **stack_a, t_list **stack_b, int target, int nbr)
{
    int count;
    int b_len;
    t_list  *a;
    
    a = *stack_a;
    count = 0;
    b_len = ft_lstsize(*stack_b);
    count += count_position(stack_b, nbr);
    if (count - 1 >= b_len / 2)
        count = b_len - count + 1;
    if (target + 1 == a->target || target - 1 == a->target)
    {
        if (target - 1 == a->target)
            count--;
        return (count + 1);
    }
    else if (target + 2 >= a->target || target - 2 <= a->target)
        return (0);
    count++;
    return (count + 1);
}

int     count_position(t_list **stk, int nbr)
{
    int i;
    t_list *stack;
    
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