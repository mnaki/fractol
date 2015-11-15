/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:50:06 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/05 00:23:09 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}
