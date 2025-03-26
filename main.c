/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:12:26 by jmenard           #+#    #+#             */
/*   Updated: 2024/09/27 11:44:57 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (av[1][0] == '\0' || check_space(av[1]) == 1)
			return (0);
		av = ft_split(av[1], ' ');
		i = 0;
	}
	if (verif_if_valid(av, i) == 0)
	{
		if (ac == 2)
			return (free_split(av), ft_putstr_fd("Error\n", 2), 0);
		else
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	create_struc(av, i, ac);
	return (0);
}

int	check_space(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	if (av)
		free(av);
}

int	calcule_cout_bis(t_list **stack_a, int goal)
{
	int		count1;
	int		a_len;
	t_list	*a;

	a = *stack_a;
	count1 = 0;
	a_len = ft_lstsize(*stack_a);
	while (a)
	{
		if (a->content == goal)
			break ;
		count1++;
		a = a->next;
	}
	if (count1 >= a_len / 2)
		count1 = a_len - count1;
	return (count1);
}
