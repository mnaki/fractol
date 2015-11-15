/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:52:24 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:52:25 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i + j])
		{
			if (s2[j] != s1[i + j])
				break ;
			++j;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		++i;
	}
	if (s2[j] == '\0')
		return ((char *)s1 + i);
	return (NULL);
}
