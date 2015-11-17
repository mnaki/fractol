/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 14:23:44 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/17 15:26:07 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(t_julia *j, int *x, int *y, int *i)
{
	t_env	*e;

	e = global_singleton();
	*x = 0;
	while (*x < e->width)
	{
		(*y) = 0;
		julia_wild(j, x, y, i);
		(*x)++;
	}
	e->c_re += ((e->wanted_value - e->c_re) / 4);
	// e->c_im += ((e->wanted_value - e->c_im) / 4);
	e->max_iter += ((e->wanted_iter - e->max_iter) / 4);
	// e->max_iter += 1;
}

void		julia_wild(t_julia *j, int *x, int *y, int *i)
{
	t_env	*e;

	e = global_singleton();
	while (*y < e->height)
	{
		julia2(j, x, y);
		(*i) = 0;
		julia_while(j, i);
		plot(x, y, i);
		(*y)++;
	}
}

void		julia_while(t_julia *j, int *i)
{
	t_env	*e;

	e = global_singleton();
	while (*i < e->max_iter)
	{
		julia3(j);
		if ((j->new_re * j->new_re + j->new_im * j->new_im) > 4)
			break ;
		(*i)++;
	}
}

void		julia2(t_julia *j, int *x, int *y)
{
	t_env	*e;

	e = global_singleton();
	j->new_re = 1.5 * (*x - e->width / 2) / (0.5 * e->zoom * e->width)
	+ e->move_x;
	j->new_im = (*y - e->height / 2) / (0.5 * e->zoom * e->height)
	+ e->move_y;
}

void		julia3(t_julia *j)
{
	t_env	*e;

	e = global_singleton();
	j->old_re = j->new_re;
	j->old_im = j->new_im;
	j->new_re = j->old_re * j->old_re - j->old_im * j->old_im
	+ e->c_re;
	j->new_im = 2 * j->old_re * j->old_im + e->c_im;
}
