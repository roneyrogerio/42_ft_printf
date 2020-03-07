/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ctype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:23:12 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/02/29 01:55:20 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_ctype(va_list args, char *flag)
{
	char			arg;
	struct s_flags	v;
	int				padding;

	v = ft_flag2struct(flag, args);
	arg = va_arg(args, int);
	padding = v.width - 1;
	if (v.left != 1)
		ft_padding(' ', padding);
	ft_putchar_fd(arg, 1);
	if (v.left == 1)
		ft_padding(' ', padding);
	return (padding >= 0 ? padding + 1 : 1);
}
