/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:35:09 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:35:10 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	char		*s1p;
	char		*s2p;

	s1p = (char *)s1;
	s2p = (char *)s2;
	while (*s1p && *s2p)
	{
		if (*s1p++ != *s2p++)
			return (0);
	}
	if (*s1p != *s2p)
		return (0);
	return (1);
}
