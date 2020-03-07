/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 02:07:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/02/29 21:36:28 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(long long int nbr)
{
	long long int	n;
	int				count;

	n = nbr;
	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
