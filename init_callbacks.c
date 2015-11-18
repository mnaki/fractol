/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_callbacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 15:16:01 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/18 13:51:39 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	callback[78] = ft_decrement_fractal;
	callback[69] = ft_increment_fractal;
	callback[18] = set1;
	callback[19] = set2;
	callback[20] = set3;
	callback[21] = set4;
}

void	init_mouse_callbacks(int (*mouse_callback[])())
{
	mouse_callback[1] = left_mouse;
	mouse_callback[2] = right_mouse;
	mouse_callback[4] = mouse_zoom;
	mouse_callback[5] = mouse_unzoom;
}
