/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:09:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 11:09:23 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ispunct(int c)
{
	if (ft_isprint(c) && !ft_isspace(c) && !ft_isalpha(c))
		return (1);
	return (0);
}
