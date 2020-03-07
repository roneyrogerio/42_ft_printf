/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec2base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:37:02 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/06 00:05:26 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_dec2base(size_t nbr, size_t base, char *symbols)
{
	size_t	syb_len;
	size_t	nbr_blen;
	size_t	buffer;
	char	*rslt;

	syb_len = ft_strlen(symbols);
	if (syb_len != base)
		return (0);
	buffer = nbr;
	nbr_blen = 0;
	while (buffer > 0)
	{
		buffer /= base;
		nbr_blen++;
	}
	rslt = ft_calloc(1, (nbr_blen ? nbr_blen : 1) + 1);
	if (!nbr_blen)
		rslt[0] = symbols[0];
	while (nbr > 0)
	{
		rslt[--nbr_blen] = symbols[nbr % base];
		nbr /= base;
	}
	return (rslt);
}
