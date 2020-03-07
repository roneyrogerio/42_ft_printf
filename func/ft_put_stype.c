/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_stype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:39:32 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/01 22:21:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_stype(va_list args, char *flag, int count)
{
	char			*arg;
	struct s_flags	v;
	int				padding;
	char			*str;
	char			*temp;

	v = ft_flag2struct(flag, args);
	arg = va_arg(args, char *);
	str = arg ? arg : ft_strdup("(null)");
	count = v.prc != -1 ? v.prc : ft_strlen(str);
	if ((int)ft_strlen(str) < v.prc)
		count = ft_strlen(str);
	padding = v.width - count;
	temp = ft_substr(str, 0, count);
	if (!arg)
		free(str);
	if (v.left != 1)
		ft_padding(v.zero == 1 ? '0' : ' ', padding);
	ft_putstr_fd(temp, 1);
	if (v.left == 1)
		ft_padding(' ', padding);
	free(temp);
	return (count + (padding > 0 ? padding : 0));
}
