/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:28:58 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:28:59 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (n--)
	{
		*(t_uchar *)(s1 + i) = *(t_uchar *)(s2 + i);
		++i;
	}
	return (s1);
}
