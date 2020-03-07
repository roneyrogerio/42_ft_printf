/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pcttype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:22:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/04 02:55:08 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_put_pcttype(char *flag, va_list args)
{
	struct s_flags	f;
	int				padding;
	int				zeros;

	f = ft_flag2struct(flag, args);
	zeros = (f.left == -1 && f.zero == 1 ? f.width - 1 : 0);
	zeros = (zeros > 0 ? zeros : 0);
	padding = f.width - zeros - 1;
	padding = (padding > 0 ? padding : 0);
	ft_padding(' ', (f.left == -1 ? padding : 0));
	ft_padding('0', zeros);
	ft_putchar_fd('%', 1);
	ft_padding(' ', (f.left == 1 ? padding : 0));
	return (zeros + padding + 1);
}
