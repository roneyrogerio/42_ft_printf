/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:25:15 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/05 17:03:19 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_lstfree(t_str2lst **lst)
{
	t_str2lst	*ptr;

	ptr = &**lst;
	while (*lst)
	{
		free(ptr->flag);
		free(ptr->before);
		*lst = ptr->next;
		free(ptr);
		ptr = &**lst;
	}
	free(*lst);
	free(lst);
}
