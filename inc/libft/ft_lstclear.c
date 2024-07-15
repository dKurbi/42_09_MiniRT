/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:36:45 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/22 21:04:41 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstcopy;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		lstcopy = *lst;
		*lst = (*lst)->next;
		del(lstcopy->content);
		free(lstcopy);
	}
}
