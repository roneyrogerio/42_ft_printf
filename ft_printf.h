/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:50:49 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/03/05 01:30:47 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_str2lst
{
	char				*flag;
	char				type;
	char				*before;
	struct s_str2lst	*next;
}				t_str2lst;

struct			s_loadv
{
	t_str2lst	**list;
	char		*before;
	char		*flag;
	size_t		i;
	size_t		bf_i;
	size_t		fl_i;
};

struct			s_flags
{
	size_t	i;
	int		zero;
	int		left;
	int		prc;
	int		width;
};

struct			s_dtype
{
	long int	nbr;
	int			len;
	int			padding;
	int			zeros;
	int			has_sig;
	int			neg;
};

t_str2lst		**ft_str2lst(const char *str);
int				ft_printf(const char *str, ...);
t_str2lst		*ft_lstnew(char *flag, char type, char *before);
void			ft_lstadd_back(t_str2lst **lst, t_str2lst *new);
t_str2lst		*ft_lstlast(t_str2lst *lst);
int				ft_istype(char c);
size_t			ft_putargs(va_list args, char type, char *flag, size_t count);
int				ft_nbrlen(long long int nbr);
void			ft_putlongnbr_fd(long long int n, int fd);
int				ft_padding(char c, int nbr);
struct s_flags	ft_flag2struct(char *flag, va_list args);
void			ft_ifnegstar(char flag, va_list args, struct s_flags *s);
char			*ft_dec2base(size_t nbr, size_t base, char *symbols);
size_t			ft_put_pcttype(char *flag, va_list args);
size_t			ft_put_stype(va_list args, char *flag, int count);
size_t			ft_put_dtype(va_list args, struct s_flags v);
size_t			ft_put_ctype(va_list args, char *flag);
size_t			ft_put_utype(va_list args, struct s_flags v);
size_t			ft_put_ptype(va_list args, struct s_flags f);
size_t			ft_put_xtype(va_list args, struct s_flags f, char *symbols);
void			ft_lstfree(t_str2lst **lst);

#endif
