/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 12:36:15 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/18 15:21:53 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_env(ssize_t width, ssize_t height, char *title, t_env *e)
{
	e->core = mlx_init();
	e->win = mlx_new_window(e->core, width, height, title);
	e->img = mlx_new_image(e->core, width, height);
	e->finish = mlx_new_image(e->core, width, height);
	init_callbacks(e->callback);
	init_mouse_callbacks(e->mouse_callback);
}

int mouse_move(int x, int y, t_env *e);
int mouse_move(int x, int y, t_env *e)
{
	static double	prev_x = 0;
	static double	prev_y = 0;

	e->wanted_im += (x - prev_x) / 10000;
	e->wanted_re += (y - prev_y) / 10000;
	e->move_x += (x - prev_x) / 1000;
	e->move_y += (y - prev_y) / 1000;
	prev_x = x;
	prev_y = y;
	ft_printf("x->\t%d\t\ty->\t%d", x, y);
	return (1);
}

void	init_hooks(t_env *e)
{
	mlx_key_hook(e->win, &key_hook, e);
	mlx_loop_hook(e->core, &loop_hook, e);
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_mouse_hook(e->win, &mouse_hook, e);
	mlx_hook(e->win, 6, (1L<<6), mouse_move, e);
}

t_env	*global_singleton(void)
{
	static t_env	e;
	static t_bool	inited = false;

	if (!inited)
	{
		inited = true;
		ft_bzero(&e, sizeof(e));
		e.zoom = 1;
		e.width = 300;
		e.height = 200;
		e.run = true;
		e.wanted_iter = 10;
		e.set = 1;
		set1();
		new_env(e.width, e.height, "Fract'Ol", &e);
		pthread_mutex_init(&e.m, NULL);
		init_hooks(&e);
	}
	return (&e);
}

int		main(void)
{
	global_singleton();
	pthread_create(&global_singleton()->t, NULL, (void*)draw, NULL);
	mlx_loop(global_singleton()->core);
	return (0);
}
