/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:52:41 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 19:52:16 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putendl_fd(char const *s, int fd)
{
	ssize_t		c;

	c = ft_putstr_fd(s, fd);
	c += ft_putchar_fd('\n', fd);
	return (c);
}
