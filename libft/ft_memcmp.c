/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:30:44 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:30:58 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	int			diff;

	i = 0;
	diff = 0;
	while (n-- && diff == 0)
	{
		diff = *(t_uchar *)(s1 + i) - *(t_uchar *)(s2 + i);
		++i;
	}
	return (diff);
}
