/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:04:28 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/04 21:21:44 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_ptype(va_list args, struct s_flags f)
{
	size_t	arg;
	char	*nbr_char;
	int		padding;
	int		zeros;
	int		len;

	arg = va_arg(args, size_t);
	nbr_char = ft_dec2base(arg, 16, "0123456789abcdef");
	len = (f.prc == 0 && arg == 0 ? 0 : ft_strlen(nbr_char));
	zeros = f.width - len - 2;
	zeros = (f.left == 1 || f.zero == -1 ? 0 : zeros);
	zeros = (f.prc >= 0 ? f.prc - len : zeros);
	zeros = (zeros > 0 ? zeros : 0);
	padding = f.width - zeros - len - 2;
	padding = padding > 0 ? padding : 0;
	ft_padding(' ', (f.left != 1 ? padding : 0));
	ft_putstr_fd("0x", 1);
	ft_padding('0', zeros);
	if (!(f.prc == 0 && arg == 0))
		ft_putstr_fd(nbr_char, 1);
	free(nbr_char);
	ft_padding(' ', (f.left == 1 ? padding : 0));
	return (padding + zeros + len + 2);
}
