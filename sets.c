/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 13:51:48 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/18 13:51:54 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set1(void)
{
	global_singleton()->set = 1;
	global_singleton()->wanted_im = 0.3;
	global_singleton()->wanted_re = 0.5;
	global_singleton()->wanted_iter = 20;
	global_singleton()->zoom = 1;
	global_singleton()->move_x = 0;
	global_singleton()->move_y = 0;
	return (1);
}

int		set2(void)
{
	global_singleton()->set = 2;
	global_singleton()->wanted_im = 0.2;
	global_singleton()->wanted_re = -0.78;
	global_singleton()->wanted_iter = 40;
	global_singleton()->zoom = 1;
	global_singleton()->move_x = 0;
	global_singleton()->move_y = 0;
	return (1);
}

int		set3(void)
{
	global_singleton()->set = 3;
	global_singleton()->wanted_im = 1;
	global_singleton()->wanted_re = 1;
	global_singleton()->wanted_iter = 30;
	global_singleton()->zoom = 1;
	global_singleton()->move_x = 0;
	global_singleton()->move_y = 0;
	return (1);
}

int		set4(void)
{
	global_singleton()->set = 4;
	global_singleton()->wanted_im = -1;
	global_singleton()->wanted_re = -1;
	global_singleton()->wanted_iter = 30;
	global_singleton()->zoom = 1;
	global_singleton()->move_x = 0;
	global_singleton()->move_y = 0;
	return (1);
}
