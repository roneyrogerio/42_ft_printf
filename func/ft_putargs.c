/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:17:45 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/06 15:01:36 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_putargs(va_list args, char type, char *flag, size_t count)
{
	if (type == '%')
		count += ft_put_pcttype(flag, args);
	else if (type == 's')
		count += ft_put_stype(args, flag, 0);
	else if (type == 'd' || type == 'i')
		count += ft_put_dtype(args, ft_flag2struct(flag, args));
	else if (type == 'c')
		count += ft_put_ctype(args, flag);
	else if (type == 'u')
		count += ft_put_utype(args, ft_flag2struct(flag, args));
	else if (type == 'p')
		count += ft_put_ptype(args, ft_flag2struct(flag, args));
	else if (type == 'x')
		count += ft_put_xtype(args,
				ft_flag2struct(flag, args), "0123456789abcdef");
	else if (type == 'X')
		count += ft_put_xtype(args,
				ft_flag2struct(flag, args), "0123456789ABCDEF");
	return (count);
}
