/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:00:14 by lgalstya          #+#    #+#             */
/*   Updated: 2022/03/30 17:28:58 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (!f || !lst)
		return (0);
	list = NULL;
	while (lst)
	{
		temp = ft_lstnew ((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&lst, *del);
			return (0);
		}
		ft_lstadd_back (&list, temp);
		lst = lst->next;
	}
	return (list);
}
