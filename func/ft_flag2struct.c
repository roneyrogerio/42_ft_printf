/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:37:08 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/04 22:07:09 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_flagconditions(char *flag, va_list args, struct s_flags *s)
{
	if (flag[s->i] == '.' && ft_isdigit(flag[s->i + 1]) && (s->i += 1))
	{
		while (flag[s->i] == '0' && ft_isdigit(flag[s->i + 1]))
			s->i++;
		s->prc = ft_atoi(&flag[s->i]);
		s->i += (ft_nbrlen(s->prc) - 1);
	}
	else if (flag[s->i] == '.' && flag[s->i + 1] == '*' && (s->i += 1))
		ft_ifnegstar('.', args, s);
	else if (flag[s->i] == '.' && !ft_isdigit(flag[s->i + 1]))
		s->prc = 0;
	else if (flag[s->i] == '0')
		s->zero = 1;
	else if (flag[s->i] == '-')
		s->left = 1;
	else if (flag[s->i] == '*')
		ft_ifnegstar('*', args, s);
	else if (ft_isdigit(flag[s->i]) && (s->width = ft_atoi(&flag[s->i])))
		s->i += (ft_nbrlen(s->width) - 1);
}

struct s_flags	ft_flag2struct(char *flag, va_list args)
{
	struct s_flags	s;

	s.i = 0;
	s.zero = -1;
	s.left = -1;
	s.prc = -1;
	s.width = -1;
	while (flag[s.i])
	{
		ft_flagconditions(flag, args, &s);
		s.i++;
	}
	return (s);
}
