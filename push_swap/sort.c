/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:00:36 by joseph            #+#    #+#             */
/*   Updated: 2024/07/29 13:29:42 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_if_sort(t_list **stack_a, t_list **stack_b)
{
    int     is_sort;

    is_sort = 0;
    while (is_sort == 0)
    {
        is_sort = sort(stack_a, stack_b);
        // ft_printf("//////////////////////////////////\n");
        // print_stack(stack_a, 'A');
	    // ft_printf("==================================\n");
	    // ft_printf("==================================\n");
	    // print_stack(stack_b, 'B');
        // ft_printf("//////////////////////////////////\n");
    }
    return (is_sort);
}

int    sort(t_list **stack_a, t_list **stack_b)
{
    int     moins_couteux;
    t_list  *b;
    t_list  *a;
    t_list  *a_bis;
    
    b = *stack_b;
    if (b == NULL)
        return (1);
    moins_couteux = less_price(stack_a, stack_b);
    while (b->content != moins_couteux)
    {
        b = *stack_b;
        if (b->content == moins_couteux)
            break ;
        if (count_position(stack_b, moins_couteux > ft_lstsize(*stack_b) / 2))
            reverse_rotate(stack_b, 'b');
        else
            rotate(stack_b, 'b');
    }
    push(stack_b, stack_a, 'a');
    a = *stack_a;
    a_bis = a->next;
    if (a->target > a_bis->target)
        rotate(stack_a, 'a');
    return (0);
}

int     less_price(t_list **stack_a, t_list **stack_b)
{
    t_list  *b;
    t_list  *b_bis;
    
    b = *stack_b;
    put_cout(stack_a, stack_b);
    b_bis = b;
    while (b_bis)
    {
        if (b_bis->cost > 0)
            break ;
        b_bis = b_bis->next;
    }
    while (b)
    {
        if (b->cost > 0)
        {
            if (b->cost < b_bis->cost)
                b_bis = b;
        }
        b = b->next;
    }
    return (b_bis->content);
}
