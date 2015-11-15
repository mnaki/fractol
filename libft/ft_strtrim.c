/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:50:50 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/10 18:12:07 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		i;
	char		t[ft_strlen(s) + 1];

	i = ft_strlen(s) - 1;
	ft_strcpy(t, s);
	while (ft_isspace(t[i]))
		--i;
	t[i + 1] = '\0';
	i = 0;
	while (ft_isspace(t[i]))
		++i;
	return (ft_strdup(t + i));
}
