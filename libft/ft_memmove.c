/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:52:09 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:52:11 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	t_uchar		tmp[n];
	size_t		i;

	(void)ft_memcpy(tmp, s2, n);
	i = 0;
	while (i < n)
	{
		*((t_uchar *)s1 + i) = tmp[i];
		++i;
	}
	return (s1);
}
