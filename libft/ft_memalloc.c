/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:35:30 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/24 21:16:42 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_garbage		*new_garbage(void *p)
{
	t_garbage			*new_garbage;

	new_garbage = (t_garbage *)malloc(sizeof(t_garbage));
	ft_bzero(new_garbage, sizeof(t_garbage));
	new_garbage->pointer = p;
	return (new_garbage);
}

static t_garbage		*add_garbage(t_garbage *new)
{
	static t_garbage	*last_garbage = NULL;

	if (last_garbage == NULL)
	{
		if ((last_garbage = (t_garbage *)malloc(sizeof(t_garbage))) == NULL)
			return (NULL);
		ft_bzero(last_garbage, sizeof(t_garbage));
	}
	if (new != NULL)
	{
		new->prev = last_garbage;
		last_garbage = new;
	}
	return (last_garbage);
}

void					*ft_memalloc(size_t size)
{
	void				*p;

	if ((p = malloc(size)) != NULL)
		ft_bzero(p, size);
	add_garbage(new_garbage(p));
	return (p);
}
