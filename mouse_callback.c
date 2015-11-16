/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_callback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 13:01:46 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/16 13:49:47 by nmohamed         ###   ########.fr       */
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
