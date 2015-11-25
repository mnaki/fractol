/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 16:29:41 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/22 16:12:39 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fracfrac(t_julia *j, int *x, int *y, int *i)
{
	t_env	*e;

	e = global_singleton();
	*x = 0;
	while (*x < e->width)
	{
		(*y) = 0;
		fracfrac_wild(j, x, y, i);
		(*x)++;
	}
}

void		fracfrac_wild(t_julia *j, int *x, int *y, int *i)
{
	t_env	*e;

	e = global_singleton();
	while (*y < e->height)
	{
		fracfrac2(j, x, y);
		(*i) = 0;
		fracfrac_while(j, i);
		plot(x, y, i);
		(*y)++;
	}
}

void		fracfrac_while(t_julia *j, int *i)
{
	t_env	*e;

	e = global_singleton();
	while (*i < e->max_iter)
	{
		fracfrac3(j);
		if ((j->new_re * j->new_re + j->new_im * j->new_im) > 4)
			break ;
		(*i)++;
	}
}

void		fracfrac2(t_julia *j, int *x, int *y)
{
	t_env	*e;

	e = global_singleton();
	j->new_re = 1.5 * (*x - e->width / 2) / (0.5 * e->final_zoom * e->width)
	+ e->final_x;
	j->new_im = (*y - e->height / 2) / (0.5 * e->final_zoom * e->height)
	+ e->final_y;
}

void		fracfrac3(t_julia *j)
{
	t_env	*e;

	e = global_singleton();
	j->old_re = j->new_im;
	j->old_im = j->new_re;
	j->new_re = j->old_re * j->old_re - j->old_im * j->old_im
	+ e->c_re;
	j->new_im = 2 * j->old_re * j->old_im + e->c_im;
}
