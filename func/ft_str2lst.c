/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:34:41 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/04 21:17:51 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_str2lst	**ft_str2lst(const char *str)
{
	struct s_loadv	v;

	v.i = 0;
	v.bf_i = 0;
	if (!(v.list = (t_str2lst **)ft_calloc(1, sizeof(t_str2lst *))))
		return (NULL);
	while (str[v.i])
	{
		if (str[v.i] == '%')
		{
			v.before = ft_substr(&str[v.bf_i], 0, v.i - v.bf_i);
			v.fl_i = ++v.i;
			while (str[v.i] && str[v.i] != '%' && !ft_isalpha(str[v.i]))
				v.i++;
			v.flag = ft_substr(&str[v.fl_i], 0, v.i - v.fl_i);
			ft_lstadd_back(v.list, ft_lstnew(v.flag, str[v.i], v.before));
			v.bf_i = (str[v.i] ? v.i + 1 : v.i);
		}
		if (!str[v.i] || (++v.i && !str[v.i]))
		{
			v.before = ft_substr(&str[v.bf_i], 0, v.i - v.bf_i);
			ft_lstadd_back(v.list, ft_lstnew(NULL, '\0', v.before));
		}
	}
	return (v.list);
}
