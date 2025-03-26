/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:15:28 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/27 11:24:18 by jmenard          ###   ########.fr       */
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
void	create_struc(char **av, int iav, int ac);
void	clear_stack(t_list **lst);
void	check_sort(t_list **stack_a, t_list **stack_b, int mediane);

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
void	put_target(t_list **stack_a, int *tab_of_int, int tab_len);
void	push_b_mini_sort(t_list **stack_a, t_list **stack_b);

//mediane_bis.c
void	push_in_bis(t_list **stack_a, t_list **stack_b, int mediane);
void	push_in_b(t_list **stack_a, t_list **stack_b, int mediane);
void	push_in_bis_bis(t_list **stack_a, t_list **stack_b, int mediane);
void	bis_bis_bis(t_list **stack_a, t_list **stack_b);

//cost.c
int		calcule_cout(t_list **stack_a, t_list **stack_b, int goal, int nbr);
int		count_position(t_list **stk, int nbr);
void	put_cout(t_list **stack_a, t_list **stack_b);
void	put_goal(t_list **stack_a, t_list **stack_b);
int		calcule_goal(t_list **stack_a, int b_target);

//sort.c
int		sort(t_list **stack_a, t_list **stack_b);
int		less_price(t_list **stack_a, t_list **stack_b);
int		check_if_sort(t_list **stack_a, t_list **stack_b);
void	tiny_sort(t_list **stack_a);
int		check_ordre(t_list **stack_a);

//put_top.c
void	put_top_a(t_list **stack_a, int nbr, int position);
void	put_top_a_bis(t_list **stack_a, int nbr, int position);
void	put_top_b(t_list **stack_b, int nbr, int position);
int		calcule_goal_bis(t_list **stack_a, int b_target);
int		count_position_bis(t_list **stk, int nbr);

//main.c
int		check_space(char *av);
void	free_split(char **av);
int		calcule_cout_bis(t_list **stack_a, int goal);

#endif