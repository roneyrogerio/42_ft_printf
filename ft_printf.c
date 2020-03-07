/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:51:41 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/05 02:47:09 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list		args;
	t_str2lst	**list;
	t_str2lst	*current;
	size_t		count;

	if (!*str)
		return (0);
	va_start(args, str);
	count = 0;
	list = ft_str2lst(str);
	current = *list;
	while (current)
	{
		count += ft_strlen(current->before);
		ft_putstr_fd(current->before, 1);
		count += ft_putargs(args, current->type, current->flag, 0);
		current = current->next;
	}
	ft_lstfree(list);
	return (count);
}
