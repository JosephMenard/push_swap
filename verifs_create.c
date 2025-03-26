/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:36:05 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/27 12:04:49 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_if_valid(char **av, int iav)
{
	int	i;

	if (is_dup(av, iav) == 0)
		return (0);
	while (av[iav])
	{
		i = 0;
		if ((av[iav][i] == '-' || av[iav][i] == '+')
			&& ft_isdigit(av[iav][i + 1]) == 1)
			i++;
		while (av[iav][i])
		{
			if (ft_isdigit(av[iav][i]) == 1)
				i++;
			else if (ft_isdigit(av[iav][i]) == 0)
				return (0);
		}
		if (ft_atoi(av[iav]) < INT_MIN || ft_atoi(av[iav]) > INT_MAX)
			return (0);
		if (ft_strlen(av[iav]) > 12 || av[iav][0] == '\0')
			return (0);
		iav++;
	}
	return (1);
}

int	is_dup(char **av, int iav)
{
	int	j;
	int	i;
	int	count;
	int	avi;

	i = iav;
	while (av[i])
	{
		j = iav;
		avi = ft_atoi(av[i]);
		count = 0;
		while (av[j])
		{
			if (ft_atoi(av[j]) == avi)
				count++;
			if (count >= 2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	create_struc(char **av, int iav, int ac)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		mediane;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (av[iav])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[iav])));
		iav++;
	}
	if (ac == 2)
		free_split(av);
	mediane = create_tab_int(&stack_a);
	check_sort(&stack_a, &stack_b, mediane);
}

void	check_sort(t_list **stack_a, t_list **stack_b, int mediane)
{
	t_list	*a;

	a = *stack_a;
	if (check_ordre(stack_a) == 0)
		clear_stack(stack_a);
	if (ft_lstsize(a) <= 3)
	{
		if (ft_lstsize(a) == 2)
		{
			if (check_ordre(stack_a) == 1)
				rotate(stack_a, 'a');
		}
		if (ft_lstsize(a) == 3)
			tiny_sort(stack_a);
		clear_stack(stack_a);
	}
	if (ft_lstsize(a) >= 4 && ft_lstsize(a) <= 10)
		push_b_mini_sort(stack_a, stack_b);
	else
		push_in_b(stack_a, stack_b, mediane);
	tiny_sort(stack_a);
	check_if_sort(stack_a, stack_b);
	clear_stack(stack_a);
}

void	clear_stack(t_list **lst)
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	*lst = NULL;
	exit (0);
}
