/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:26:48 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:26:51 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, t_uint start, size_t len)
{
	char		tmp[len];

	(void)ft_strncpy(tmp, s + start, len);
	tmp[len] = '\0';
	return (ft_strdup(tmp));
}
