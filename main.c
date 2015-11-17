/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 12:36:15 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/17 14:25:07 by nmohamed         ###   ########.fr       */
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

void	init_hooks(t_env *e)
{
	mlx_key_hook(e->win, &key_hook, e);
	mlx_loop_hook(e->core, &loop_hook, e);
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_mouse_hook(e->win, &mouse_hook, e);
}

t_env	*global_singleton(void)
{
	static t_env	e;
	static t_bool	inited = false;

	if (!inited)
	{
		ft_bzero(&e, sizeof(e));
		e.c_re = 0;
		e.c_im = 0;
		e.zoom = 1;
		e.move_x = 0;
		e.move_y = 0;
		e.max_iter = 0;
		e.width = 300;
		e.height = 200;
		e.run = true;
		e.wanted_value = 0;
		new_env(e.width, e.height, "Fract'Ol", &e);
		pthread_mutex_init(&e.m, NULL);
		init_hooks(&e);
		inited = true;
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
