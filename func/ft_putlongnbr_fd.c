/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:41:45 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/02/29 02:58:12 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putlongnbr_fd(long long int n, int fd)
{
	long long int	i;
	char			c[19];

	if (fd < 0)
		return ;
	if (n == -9223372036854775807LL - 1LL)
	{
		ft_putstr_fd("-9223372036854775808", fd);
		return ;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0 && (n = -n))
		ft_putchar_fd('-', fd);
	i = 0;
	while (n > 0)
	{
		c[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(c[i--], fd);
}
