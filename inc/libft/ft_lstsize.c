/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:40:49 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/22 21:08:57 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*lstcount;

	i = 0;
	lstcount = lst;
	while (lstcount != NULL)
	{
		i++;
		lstcount = lstcount->next;
	}
	return (i);
}
