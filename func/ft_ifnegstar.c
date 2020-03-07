/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifnegstar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:52:41 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/02 01:11:39 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_ifnegstar(char flag, va_list args, struct s_flags *s)
{
	long long int	nbr;

	nbr = va_arg(args, int);
	if (flag == '.' && nbr < 0)
		s->prc = -1;
	else if (flag == '.' && nbr >= 0)
		s->prc = nbr;
	else if (flag == '*')
	{
		if (nbr < 0)
		{
			s->left = 1;
			nbr = -nbr;
		}
		s->width = nbr;
	}
}
