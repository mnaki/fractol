/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 15:52:50 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/21 18:23:05 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandel_plot(int x, int y, int color)
{
	t_env	*e;

	e = global_singleton();
	pthread_mutex_lock(&e->m);
	put_pixel_to_img(x, y, color, e);
	pthread_mutex_unlock(&e->m);
}

void		mandelbrot(int *i_x, int *i_y, int *i_i)
{
	t_env	*e;
	float	x;
	float	y;

	e = global_singleton();
	(*i_x) = 0;
	while ((*i_x) < e->width)
	{
		(*i_y) = 0;
		while ((*i_y) < e->height)
		{
			e->c_im = (*i_x - e->width / 2.0) * 4.0 / e->width / e->final_zoom;
			e->c_re = (*i_y - e->height / 2.0) * 4.0 / e->width / e->final_zoom;
			x = 0;
			y = 0;
			(*i_i) = 0;
			while (x * x + y * y <= 4 && (*i_i) < e->max_iter)
				mandel_while(&x, &y, i_i);
			plot((i_x), (i_y), (i_i));
			(*i_y)++;
		}
		(*i_x)++;
	}
}

void		mandel_while(float *x, float *y, int *i_i)
{
	t_env		*e;
	float		x_new;

	e = global_singleton();
	x_new = *x * *x - *y * *y + e->c_re;
	*y = 2 * *x * *y + e->c_im + e->final_x;
	*x = x_new + e->final_y;
	(*i_i)++;
}
