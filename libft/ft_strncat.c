/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:31:09 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:31:19 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*o;

	o = s1;
	s1 = ft_strchr(s1, '\0');
	i = 0;
	while (n--)
	{
		if (s2[i])
			s1[i] = s2[i];
		++i;
	}
	return (o);
}
