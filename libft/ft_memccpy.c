/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:52:15 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:52:16 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;
	t_uchar		uc;
	t_uchar		*s1p;
	t_uchar		*s2p;

	i = 0;
	s1p = s1;
	s2p = (t_uchar *)s2;
	uc = c;
	while (n--)
	{
		s1p[i] = s2p[i];
		if (s1p[i] == uc)
			return (s1p + i + 1);
		++i;
	}
	return (NULL);
}
