/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 19:18:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/21 19:48:21 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	for_each(void *a, void (f)(void *a))
{
	size_t		i;
	char		**ap;

	i = 0;
	ap = a;
	while (ap[i] != NULL)
	{
		f(ap[i]);
		++i;
	}
}
