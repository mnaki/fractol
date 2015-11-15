/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 12:36:15 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 19:24:21 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_env(ssize_t width, ssize_t height, char *title, t_env *e)
{
	ft_bzero(e, sizeof(*e));
	e->core = mlx_init();
	e->win = mlx_new_window(e->core, width, height, title);
	e->img = mlx_new_image(e->core, WIDTH, HEIGHT);
	e->finish = mlx_new_image(e->core, WIDTH, HEIGHT);
	init_callbacks(e->callback);
}

void	init_singleton(t_env *e)
{
	mlx_key_hook(e->win, &key_hook, e);
	mlx_loop_hook(e->core, &loop_hook, e);
	mlx_expose_hook(e->win, &expose_hook, e);
}

t_env	*global_singleton(void)
{
	static t_env	e;
	static t_bool	inited = false;

	if (!inited)
	{
		new_env(WIDTH, HEIGHT, "Fract'Ol", &e);
		init_singleton(&e);
		e.c_re = -0.7;
		e.c_im = .27015;
		e.zoom = 1;
		e.move_x = 0;
		e.move_y = 0;
		e.max_iter = 0;
		e.width = WIDTH;
		e.height = HEIGHT;
		pthread_mutex_init(&e.m, NULL);
		inited = true;
	}
	return (&e);
}

int		main(void)
{
	static	pthread_t t;
	global_singleton();
	pthread_create(&t, NULL, (void*)draw, NULL);
	mlx_loop(global_singleton()->core);
	return (0);
}
