/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_seg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 10:14:18 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 15:51:45 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_seg(t_vec2 *vec, unsigned int color, t_env *e)
{
	put_pixel_to_img(vec->x, vec->y, color, e);
	if (fabs(vec->dx - vec->x) > fabs(vec->dy - vec->y))
		draw_seg_aux(vec, color, e);
	else
		draw_seg_alt(vec, color, e);
}

void	draw_seg_aux(t_vec2 *vec, unsigned int color, t_env *e)
{
	int		dx;
	int		dy;
	int		i;
	int		cumul;

	dx = vec->dx - vec->x;
	dy = vec->dy - vec->y;
	cumul = abs(dx) / 2;
	i = 1;
	while (i++ <= abs(dx))
	{
		vec->x += (dx > 0) ? 1 : -1;
		cumul += abs(dy);
		if (cumul >= abs(dx))
		{
			cumul -= abs(dx);
			vec->y += (dy > 0) ? 1 : -1;
		}
		put_pixel_to_img(vec->x, vec->y, color, e);
	}
}

void	draw_seg_alt(t_vec2 *vec, unsigned int color, t_env *e)
{
	int		dx;
	int		dy;
	int		i;
	int		cumul;

	dx = vec->dx - vec->x;
	dy = vec->dy - vec->y;
	cumul = abs(dy) / 2;
	i = 1;
	while (i++ <= abs(dy))
	{
		vec->y += (dy > 0) ? 1 : -1;
		cumul += abs(dx);
		if (cumul >= abs(dy))
		{
			cumul -= abs(dy);
			vec->x += (dx > 0) ? 1 : -1;
		}
		put_pixel_to_img(vec->x, vec->y, color, e);
	}
}
