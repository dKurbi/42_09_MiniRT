/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:10:49 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/24 17:37:14 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*arr;
	t_list	*new;
	void	*contentlst;

	if (!(lst) || !(f) || !(del))
		return (NULL);
	arr = NULL;
	while (lst != NULL)
	{
		contentlst = lst->content;
		new = ft_lstnew(contentlst);
		if (!(new))
		{
			ft_lstclear(&arr, del);
			return (NULL);
		}
		new->content = f(contentlst);
		if (!arr)
			arr = new;
		else
			ft_lstadd_back(&arr, new);
		lst = lst->next;
	}
	return (arr);
}
