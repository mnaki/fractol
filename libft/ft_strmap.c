/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:29:03 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:29:05 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	char		*s2;

	i = 0;
	s2 = ft_strdup(s);
	while (s2[i])
	{
		s2[i] = f(s[i]);
		++i;
	}
	return (s2);
}
