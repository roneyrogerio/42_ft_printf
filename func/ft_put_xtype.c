/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_xtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:17:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/04 21:35:13 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_xtype(va_list args, struct s_flags f, char *symbols)
{
	char			*nbr_char;
	unsigned int	nbr;
	int				len;
	int				zeros;
	int				padding;

	nbr = va_arg(args, unsigned int);
	nbr_char = ft_dec2base(nbr, 16, symbols);
	len = (f.prc == 0 && nbr == 0 ? 0 : ft_strlen(nbr_char));
	zeros = f.width - len;
	zeros = (f.left == 1 || f.zero == -1 ? 0 : zeros);
	zeros = (f.prc >= 0 ? f.prc - len : zeros);
	zeros = (zeros > 0 ? zeros : 0);
	padding = f.width - zeros - len;
	padding = (padding > 0 ? padding : 0);
	ft_padding(' ', f.left == -1 ? padding : 0);
	ft_padding('0', zeros);
	if (!(f.prc == 0 && nbr == 0))
		ft_putstr_fd(nbr_char, 1);
	ft_padding(' ', f.left == 1 ? padding : 0);
	free(nbr_char);
	return (len + zeros + padding);
}
