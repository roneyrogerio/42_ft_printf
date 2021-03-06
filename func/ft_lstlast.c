/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:40:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/02/19 17:51:58 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_str2lst	*ft_lstlast(t_str2lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
