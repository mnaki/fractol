/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 09:38:00 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 19:24:11 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_hook(t_env *e)
{
	fill_img(0x000000, e);
	pthread_mutex_lock(&e->m);
	mlx_put_image_to_window(e->core, e->win, e->img, 0, 0);
	pthread_mutex_unlock(&e->m);
	e->max_iter += 1;
	return (1);
}

int		key_hook(int k, t_env *e)
{
	ft_printf("key -> %d\n", k);
	if (k >= MAX_CALLBACKS || e->callback[k] == NULL)
		return (0);
	return (e->callback[k](k, e));
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
	double	new_re;
	double	new_im;
	double	old_im;
	double	old_re;
	int i;
	t_env	*e;

	e = global_singleton();
	while (1)
	{
		x = 0;
		while (x < e->width)
		{
			y = 0;
			while (y < HEIGHT)
			{
				new_re = 1.5 * (x - e->width / 2) / (0.5 * e->zoom * e->width) + e->move_x;
				new_im = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->move_y;
				i = 0;
				while (i < e->max_iter)
				{
					old_re = new_re;
					old_im = new_im;
					new_re = old_re * old_re - old_im * old_im + e->c_re;
					new_im = 2 * old_re * old_im + e->c_im;
					if ((new_re * new_re + new_im * new_im) > 4)
						break ;
					i++;
				}
				pthread_mutex_lock(&e->m);
				put_pixel_to_img(x, y, 0x110000 * ((double)i/10), e);
				pthread_mutex_unlock(&e->m);
				y++;
			}
			x++;
		}
	}
}
