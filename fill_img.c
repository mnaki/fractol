/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 15:17:31 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/16 00:31:16 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_img(unsigned int color, t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->height)
	{
		x = 0;
		while (x < e->width)
		{
			put_pixel_to_img(x, y, color, e);
			x++;
		}
		y++;
	}
}
