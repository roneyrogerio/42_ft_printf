/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:17:28 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/04 22:57:10 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_utype(va_list args, struct s_flags v)
{
	unsigned int	nbr;
	int				len;
	int				padding;
	int				zeros;

	nbr = va_arg(args, unsigned int);
	len = (v.prc == 0 && nbr == 0 ? 0 : ft_nbrlen(nbr));
	zeros = v.width - len;
	zeros = (v.left == 1 || v.zero == -1 ? 0 : zeros);
	zeros = (v.prc >= 0 ? v.prc - len : zeros);
	zeros = (zeros > 0 ? zeros : 0);
	padding = v.width - len - zeros;
	padding = padding > 0 ? padding : 0;
	if (v.left != 1)
		ft_padding(' ', padding);
	ft_padding('0', zeros);
	if (!(v.prc == 0 && nbr == 0))
		ft_putlongnbr_fd(nbr, 1);
	if (v.left == 1)
		ft_padding(' ', padding);
	return (len + zeros + padding);
}
