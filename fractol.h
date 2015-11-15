/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:15:51 by nmohamed          #+#    #+#             */
/*   Updated: 2015/11/15 18:56:22 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include "libft.h"
# define WIDTH			1280
# define HEIGHT			720
# define MAX_CALLBACKS	65536

typedef struct s_env	t_env;
typedef struct s_vec2	t_vec2;

struct					s_env
{
	void				*core;
	void				*win;
	void				*img;
	int					width;
	int					height;
	int					(*callback[MAX_CALLBACKS])(int k, t_env *e);
	double				c_re;
	double				c_im;
	double				zoom;
	double				move_x;
	double				move_y;
	int					max_iter;
};

struct					s_vec2
{
	double				x;
	double				y;
	double				dx;
	double				dy;
};

t_env					*global_singleton(void);

void					init_callbacks(int (*callback[])());
void					new_env(ssize_t w, ssize_t h, char *title, t_env *e);
void					init_singleton(t_env *e);

void					put_pixel_to_img(int x, int y, t_uint color, t_env *e);

int						loop_hook(t_env *e);
int						key_hook(int k, t_env *e);
int						expose_hook(t_env *e);
void					draw(void);

void					fill_img(unsigned int color, t_env *e);
int						ft_exit(int k, t_env *e);

void					draw_seg(t_vec2 *vec, unsigned int color, t_env *e);
void					draw_seg_aux(t_vec2 *vec, unsigned int color, t_env *e);
void					draw_seg_alt(t_vec2 *vec, unsigned int color, t_env *e);

int						ft_zoom_minus(void);
int						ft_zoom_plus(void);
int						ft_move_up(void);
int						ft_move_down(void);
int						ft_move_left(void);
int						ft_move_right(void);

#endif
