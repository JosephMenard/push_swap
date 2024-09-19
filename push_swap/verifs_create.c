/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:36:05 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/29 09:15:41 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_if_valid(char **av, int iav)
{
	int	i;

	if (is_dup(av, iav) == 0)
		return (ft_printf("Il y a deux chiffre similaire\n"), 0);
	while (av[iav])
	{
		i = 0;
		if (av[iav][i] == '-')
			i++;
		while (av[iav][i])
		{
			if (ft_isdigit(av[iav][i]) == 1)
				i++;
			else if (ft_isdigit(av[iav][i]) == 0)
				return (ft_printf("Une des entree n'est pas un INT\n"), 0);
		}
		if (ft_atoi(av[iav]) < INT_MIN || ft_atoi(av[iav]) > INT_MAX)
			return (ft_printf("Une des entree depasse INT_MIN ou INT_MAX\n"), 0);
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
				return (ft_printf("chiffre en double; %d\n", ft_atoi(av[j])), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	create_struc(char **av, int iav)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		mediane;

	stack_a = NULL;
	stack_b = NULL;
	while (av[iav])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[iav])));
		iav++;
	}
	mediane = create_tab_int(&stack_a);
	push_in_b(&stack_a, &stack_b, mediane);
	check_if_sort(&stack_a, &stack_b);
}
