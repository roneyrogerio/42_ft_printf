/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:36:26 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/02/19 17:50:29 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_str2lst	*ft_lstnew(char *flag, char type, char *before)
{
	t_str2lst	*list;

	if (!(list = (t_str2lst *)ft_calloc(1, sizeof(t_str2lst))))
		return (NULL);
	list->flag = flag;
	list->before = before;
	list->type = type;
	list->next = NULL;
	return (list);
}
