/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:35:24 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 12:44:26 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		l1;

	l1 = ft_strlen(s1);
	if ((s3 = ft_strnew(l1 + ft_strlen(s2))) != NULL)
	{
		(void)ft_strcpy(s3, s1);
		(void)ft_strcat(s3, s2);
	}
	return (s3);
}
