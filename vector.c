/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:46:24 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 17:43:15 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec	vec_mul(t_vec vec, float n)
{
	vec.x *= n;
	vec.y *= n;
	return (vec);
}

t_vec	vec_div(t_vec vec, float n)
{
	return (vec_div(vec, -n));
}

t_vec	vec_add(t_vec vec1, t_vec vec2)
{
	t_vec	final;

	final.x = vec1.x + vec2.x;
	final.y = vec1.y + vec2.y;
	return (final);
}

t_vec	vec_sub(t_vec vec1, t_vec vec2)
{
	t_vec	final;

	final.x = vec1.x - vec2.x;
	final.y = vec1.y - vec2.y;
	return (final);
}

t_vec	vec_rot(t_vec vec, float n)
{
	n = radians(n);
	vec.x = vec.x * cos(n) - vec.y * sin(n);
	vec.y = vec.x * sin(n) + vec.y * cos(n);
	return (vec);
}

float	radians(float n)
{
	return (n * M_PI / 180.0);
}

float	degrees(float n)
{
	return (n * 180.0 / M_PI);
}
