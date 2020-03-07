/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:53:43 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/02/08 20:40:27 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rslt;

	i = 0;
	if (!s || !(rslt = (char *)malloc(ft_strlen(s) + 1 * sizeof(char))))
		return (NULL);
	while (s[i] && (i += 1))
		rslt[i - 1] = f(i - 1, s[i - 1]);
	rslt[i] = '\0';
	return (rslt);
}
