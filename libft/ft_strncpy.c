/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:26:05 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:26:10 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char		*s1p;
	char		*s2p;

	s1p = s1;
	s2p = (char *)s2;
	while (n > 0 && *s2p)
	{
		*s1p++ = *s2p++;
		--n;
	}
	while (n > 0)
	{
		*s1p++ = '\0';
		--n;
	}
	return (s1);
}
