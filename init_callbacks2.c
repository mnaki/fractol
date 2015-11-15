/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_callbacks2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:13:20 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 18:53:55 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_move_up(void)
{
	ft_printf("%s\n", "up");
	return (1);
}

int		ft_move_down(void)
{
	ft_printf("%s\n", "down");
	return (1);
}

int		ft_move_left(void)
{
	ft_printf("%s\n", "left");
	return (1);
}

int		ft_move_right(void)
{
	ft_printf("%s\n", "right");
	return (1);
}
