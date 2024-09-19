/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:14 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/26 17:03:38 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(long int content)
{
	t_list	*list_content;

	list_content = malloc(sizeof(struct s_list));
	if (!list_content)
		return (NULL);
	list_content->content = content;
	list_content->target = 0;
	list_content->cost = 0;
	list_content->next = NULL;
	list_content->prev = NULL;
	return (list_content);
}
