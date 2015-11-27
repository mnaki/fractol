/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_callback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 13:01:46 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/27 17:03:23 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		left_mouse(int button, int x, int y, t_env *e)
{
	ft_printf("button -> %d\tx -> %d\ty -> %d\n", button, x, y);
	x = x - e->width / 2;
	y = y - e->height / 2;
	e->move_x += (double)x / (e->height / 2) / e->zoom;
	e->move_y += (double)y / (e->height / 2) / e->zoom;
	ft_zoom_plus();
	return (1);
}

int		right_mouse(int button, int x, int y, t_env *e)
{
	ft_printf("button -> %d\tx -> %d\ty -> %d\n", button, x, y);
	x = x - e->width / 2;
	y = y - e->height / 2;
	e->move_x -= (double)x / (e->height / 2) / e->zoom;
	e->move_y -= (double)y / (e->height / 2) / e->zoom;
	ft_zoom_minus();
	return (1);
}

double	g_zoom_coef = 0.075;

int		mouse_zoom(int button, int x, int y, t_env *e)
{
	ft_printf("button -> %d\tx -> %d\ty -> %d\n", button, x, y);
	x = x - e->width / 2;
	y = y - e->height / 2;
	e->move_x += (double)x / (e->height * 8) / e->zoom;
	e->move_y += (double)y / (e->height * 8) / e->zoom;
	e->zoom *= 1.0 + g_zoom_coef;
	(void)x;
	(void)y;
	(void)button;
	return (1);
}

int		mouse_unzoom(int button, int x, int y, t_env *e)
{
	ft_printf("button -> %d\tx -> %d\ty -> %d\n", button, x, y);
	x = x - e->width / 2;
	y = y - e->height / 2;
	e->move_x -= (double)x / (e->height * 8) / e->zoom;
	e->move_y -= (double)y / (e->height * 8) / e->zoom;
	e->zoom *= 1.0 - g_zoom_coef;
	(void)x;
	(void)y;
	(void)button;
	return (1);
}
