/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_callbacks3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 13:51:26 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/18 13:51:34 by nmohamed         ###   ########.fr       */
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

int		ft_increment_fractal(void)
{
	global_singleton()->wanted_iter += 10;
	return (1);
}

int		ft_decrement_fractal(void)
{
	global_singleton()->wanted_iter -= 10;
	return (1);
}
