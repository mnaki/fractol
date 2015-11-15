/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:35:16 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:35:18 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char		*s1p;
	char		*s2p;

	s1p = (char *)s1;
	s2p = (char *)s2;
	while (n-- > 0 && *s1p && *s2p)
	{
		if (*s1p++ != *s2p++)
			return (0);
	}
	return (1);
}
