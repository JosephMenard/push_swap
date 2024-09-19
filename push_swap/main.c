/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:12:26 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/27 15:49:15 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	if (verif_if_valid(av, i) == 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	create_struc(av, i);
	return (0);
}
