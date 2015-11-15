/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:58:16 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:58:18 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putint_pf(va_list *arg)
{
	int			i;
	char		*s;

	i = va_arg(*arg, int);
	s = ft_itoa(i);
	i = write(1, s, ft_strlen(s));
	free(s);
	return (i);
}

int			ft_putt_uint_pf(va_list *arg)
{
	t_uint		i;
	char		*s;

	i = va_arg(*arg, int);
	s = ft_itoa_u(i);
	i = write(1, s, ft_strlen(s));
	free(s);
	return (i);
}

int			ft_putchar_pf(va_list *arg)
{
	char		c;

	c = (char)va_arg(*arg, int);
	return (write(1, &c, 1));
}

int			ft_putstr_pf(va_list *arg)
{
	char		*s;
	int			count;

	s = va_arg(*arg, char *);
	if (!s)
		return (count = write(1, "(null)", 6));
	count = write(1, s, ft_strlen(s));
	return (count);
}

int			ft_putaddr_pf(va_list *arg)
{
	t_luint		a;
	char		*p;

	a = va_arg(*arg, unsigned long int);
	p = ft_itoa_u(a);
	a = write(1, p, ft_strlen(p));
	free(p);
	return (a);
}
