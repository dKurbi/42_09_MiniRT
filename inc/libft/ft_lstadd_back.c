/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:23:22 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/22 21:02:11 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstcpy;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lstcpy = *lst;
	while (lstcpy->next != NULL)
		lstcpy = lstcpy->next;
	lstcpy->next = new;
}
