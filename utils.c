/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 14:07:46 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/21 17:15:46 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		g_color = 0x00aa00;

void	ft_swap(void *a, void *b)
{
	void	*c;

	c = *(void**)a;
	*(void**)a = *(void**)b;
	*(void**)b = c;
}

void	draw(void)
{
	int		x;
	int		y;
	t_julia	j;
	int		i;
	t_env	*e;

	e = global_singleton();
	while (1)
	{
		clear_buffer();
		e->c_re += ((e->wanted_re - e->c_re) / 4);
		e->c_im += ((e->wanted_im - e->c_im) / 4);
		e->max_iter += ((e->wanted_iter - e->max_iter) / 4);
		e->final_x += ((e->move_x - e->final_x) / 4);
		e->final_y += ((e->move_y - e->final_y) / 4);
		e->final_zoom += ((e->zoom - e->final_zoom) / 4);
		if (e->set == 1 || e->set == 2)
			julia(&j, &x, &y, &i);
		else if (e->set == 3)
			mandelbrot(&x, &y, &i);
		else if (e->set == 4)
			newton(&x, &y, &i);
		swap_buffer();
		usleep(1000000 / 25);
	}
}

void	plot(int *x, int *y, int *i)
{
	t_env	*e;

	e = global_singleton();
	pthread_mutex_lock(&e->m);
	put_pixel_to_img(*x, *y, *i * (-g_color & g_color), e);
	pthread_mutex_unlock(&e->m);
}

void	swap_buffer(void)
{
	t_env	*e;

	e = global_singleton();
	pthread_mutex_lock(&e->m);
	ft_swap(&e->img, &e->finish);
	pthread_mutex_unlock(&e->m);
}

void	clear_buffer(void)
{
	t_env	*e;

	e = global_singleton();
	pthread_mutex_lock(&e->m);
	if (!e->run)
		pthread_exit(0);
	fill_img(((2 * 0x191919) * 0x009900), e);
	pthread_mutex_unlock(&e->m);
}
