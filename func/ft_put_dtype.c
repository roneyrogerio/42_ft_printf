/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:39:15 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/06 00:23:22 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_dtype(va_list args, struct s_flags f)
{
	struct s_dtype	v;

	v.neg = 0;
	v.nbr = va_arg(args, int);
	if (v.nbr < 0 && (v.nbr = -v.nbr))
		v.neg = 1;
	v.len = (f.prc == 0 && v.nbr == 0 ? 0 : ft_nbrlen(v.nbr));
	v.has_sig = v.neg ? 1 : 0;
	v.zeros = f.width - v.len - v.has_sig;
	v.zeros = (f.left == 1 || f.zero == -1 ? 0 : v.zeros);
	v.zeros = (f.prc >= 0 ? f.prc - v.len : v.zeros);
	v.zeros = (v.zeros < 0 ? 0 : v.zeros);
	v.padding = f.width - v.zeros - v.len - v.has_sig;
	v.padding = v.padding < 0 ? 0 : v.padding;
	ft_padding(' ', (f.left != 1 ? v.padding : 0));
	if (v.has_sig)
		ft_putchar_fd('-', 1);
	ft_padding('0', (v.zeros ? v.zeros : 0));
	if (!(f.prc == 0 && v.nbr == 0))
		ft_putlongnbr_fd(v.nbr, 1);
	ft_padding(' ', (f.left == 1 ? v.padding : 0));
	return (v.padding + v.has_sig + v.zeros + v.len);
}
