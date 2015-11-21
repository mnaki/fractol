/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_callbacks3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 13:51:26 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/21 16:19:38 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_zoom_minus(void)
{
	ft_printf("%s\n", "unzoom");
	global_singleton()->zoom *= 0.9;
	return (1);
}

int		ft_zoom_plus(void)
{
	ft_printf("%s\n", "zoom");
	global_singleton()->zoom *= 1.1;
	return (1);
}

int		ft_increment_fractal(void)
{
	global_singleton()->wanted_iter += 1;
	return (1);
}

int		ft_decrement_fractal(void)
{
	global_singleton()->wanted_iter -= 1;
	return (1);
}
