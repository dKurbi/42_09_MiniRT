/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassambe <iassambe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:54 by iassambe          #+#    #+#             */
/*   Updated: 2023/05/22 21:33:50 by iassambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_arr;

	t_arr = (t_list *) malloc(sizeof(t_list));
	if (t_arr == NULL)
		return (NULL);
	t_arr->content = content;
	t_arr->next = NULL;
	return (t_arr);
}
