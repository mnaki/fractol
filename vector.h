/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:46:29 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 17:42:33 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	float		x;
	float		y;
}				t_vec;

t_vec vec_mul(t_vec vec, float n);
t_vec vec_div(t_vec vec, float n);
t_vec vec_add(t_vec vec1, t_vec vec2);
t_vec vec_sub(t_vec vec1, t_vec vec2);
t_vec vec_rot(t_vec vec, float n);

float radians(float n);
float degrees(float n);

#endif
