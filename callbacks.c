/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 15:17:52 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/16 12:46:53 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "errno.h"
#include "stdio.h"

int		ft_exit(int k, t_env *e)
{
	pthread_mutex_lock(&e->m);
	e->run = false;
	mlx_destroy_image(e->core, e->img);
	mlx_destroy_image(e->core, e->finish);
	mlx_destroy_window(e->core, e->win);
	(void)k;
	exit(0);
	pthread_mutex_unlock(&e->m);
}
