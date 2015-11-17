/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 09:38:00 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/16 14:41:40 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_swap(void *a, void *b)
{
	void	*c;

	c = *(void**)a;
	*(void**)a = *(void**)b;
	*(void**)b = c;
}

int		loop_hook(t_env *e)
{
	pthread_mutex_lock(&e->m);
	mlx_put_image_to_window(e->core, e->win, e->finish, 0, 0);
	pthread_mutex_unlock(&e->m);
	return (1);
}

int		key_hook(int k, t_env *e)
{
	ft_printf("key -> %d\n", k);
	if (k >= MAX_CALLBACKS || e->callback[k] == NULL)
		return (0);
	return (e->callback[k](k, e));
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	ft_printf("mouse -> %d\n", button);
	if (button >= MAX_CALLBACKS || e->mouse_callback[button] == NULL)
		return (0);
	return (e->mouse_callback[button](button, x, y, e));
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->core, e->win);
	mlx_put_image_to_window(e->core, e->win, e->img, 0, 0);
	return (1);
}

void	draw(void)
{
	int		x;
	int		y;
	t_julia	j;
	int		i;

	while (1)
	{
		clear_buffer();
		julia(&j, &x, &y, &i);
		swap_buffer();
	}
}

void	plot(int *x, int *y, int *i)
{
	t_env	*e;

	e = global_singleton();
	pthread_mutex_lock(&e->m);
	put_pixel_to_img(*x, *y, 0x110000 * (*i) % 0xffffff, e);
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
	fill_img(0xffffff, e);
	pthread_mutex_unlock(&e->m);
}
