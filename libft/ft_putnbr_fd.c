/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:55:12 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/16 11:39:39 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putnbr_fd(int n, int const fd)
{
	char		*str;
	ssize_t		count;

	str = ft_itoa(n);
	count = ft_putstr_fd(str, fd);
	ft_strdel(&str);
	return (count);
}
