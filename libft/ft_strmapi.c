/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:28:25 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:28:26 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*s2;

	i = 0;
	s2 = ft_strdup(s);
	while (s2[i])
	{
		s2[i] = f(i, s[i]);
		++i;
	}
	return (s2);
}
