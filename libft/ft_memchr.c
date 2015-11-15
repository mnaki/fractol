/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:36:06 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:36:08 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar		*sp;
	t_uchar		uc;
	size_t		i;

	uc = (t_uchar)c;
	sp = (void *)s;
	i = 0;
	while (n--)
	{
		if (sp[i] == uc)
			return (&sp[i]);
		++i;
	}
	return (NULL);
}
