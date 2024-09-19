/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:15:28 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/28 19:38:45 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<limits.h>
# include"./libft/libft.h"

//verif_create.c
int		verif_if_valid(char **av, int iav);
int		is_dup(char **av, int iav);
void	create_struc(char **av, int iav);

//instructions.c et instruction_bis.c
void	swap(t_list **stack, char c);
void	rotate(t_list **stack, char c);
void	reverse_rotate(t_list **stack, char c);
void	push(t_list **source, t_list **dest, char c);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	print_stack(t_list **stk, char c);

//mediane.c
int		create_tab_int(t_list **stack_a);
int		calcule_mediane(int *tab_of_int, int tab_len, t_list **stack_a);
void	push_in_b(t_list **stack_a, t_list **stack_b, int	mediane);
void	put_target(t_list **stack_a, int *tab_of_int, int tab_len);

//cost.c
int     calcule_cout(t_list **stack_a, t_list **stack_b, int target, int nbr);
int     count_position(t_list **stk, int nbr);
void    put_cout(t_list **stack_a, t_list **stack_b);

//sort.c
int    sort(t_list **stack_a, t_list **stack_b);
int     less_price(t_list **stack_a, t_list **stack_b);
int     check_if_sort(t_list **stack_a, t_list **stack_b);

#endif