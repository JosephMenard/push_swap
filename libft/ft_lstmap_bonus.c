/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:17:00 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/18 14:26:04 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, long int (*f)(long int), void (*del)(long int))
{
	t_list		*new_elem;
	t_list		*new_lst;
	long int	new_f;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_f = f(lst->content);
		new_elem = ft_lstnew(new_f);
		if (!new_elem)
		{
			del(new_f);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
