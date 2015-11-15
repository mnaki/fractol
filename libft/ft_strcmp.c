/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:31:03 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:31:18 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;
	int			diff;

	i = 0;
	diff = 0;
	while (diff == 0 && s1[i] && s2[i])
	{
		diff = s1[i] - s2[i];
		++i;
	}
	return (diff);
}
