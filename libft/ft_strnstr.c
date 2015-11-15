/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:52:20 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:52:20 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (n > 0 && s1[i])
	{
		j = 0;
		while (n-- > 0 && s2[j] && s1[i + j])
		{
			if (s2[j] != s1[i + j])
				break ;
			++j;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		++i;
	}
	return (NULL);
}
