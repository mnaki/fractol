/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:28:45 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:28:46 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		++i;
	}
	s1[i] = s2[i];
	return (s1);
}
