/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_callbacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 15:16:01 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/16 14:03:15 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_zoom_minus(void)
{
	ft_printf("%s\n", "unzoom");
	global_singleton()->zoom *= 0.5;
	return (1);
}

int		ft_zoom_plus(void)
{
	ft_printf("%s\n", "zoom");
	global_singleton()->zoom *= 1.5;
	return (1);
}

void	init_callbacks(int (*callback[])())
{
	callback[53] = ft_exit;
	callback[12] = ft_exit;
	callback[27] = ft_zoom_minus;
	callback[24] = ft_zoom_plus;
	callback[126] = ft_move_up;
	callback[125] = ft_move_down;
	callback[123] = ft_move_left;
	callback[124] = ft_move_right;
}

void	init_mouse_callbacks(int (*mouse_callback[])())
{
	mouse_callback[1] = left_mouse;
	mouse_callback[2] = right_mouse;
	mouse_callback[4] = mouse_zoom;
	mouse_callback[5] = mouse_unzoom;
}
