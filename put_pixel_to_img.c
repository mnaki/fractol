/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 09:36:23 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 23:45:55 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(int x, int y, unsigned int color, t_env *e)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	if (x >= e->width || x < 0 || y >= e->height || y < 0)
		return ;
	data = mlx_get_data_addr(e->img, &bpp, &size_line, &endian);
	data[(y
		* size_line)
		+ x
		* (bpp / 8) + 2] = color >> 16;
	data[(y
		* size_line)
		+ x
		* (bpp / 8) + 1] = color >> 8;
	data[(y
		* size_line)
		+ x
		* (bpp / 8) + 0] = color;
}
