/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:56:08 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/28 16:51:48 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FT_FRACT_H
# define FRACTOL_FT_FRACT_H

# define W 1200
# define H 1200
# define T 6

# define SQRT(x) ((x) * (x))

# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct		s_newtondata
{
	int				fr;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	double			f[3];
	double			ph[3];
	double			w[3];
	double			c[3];
	double			dx;
	double			dy;
	double			z;
	int				change_phi;
	int				flag;
	int				maxiters;
	int				iters;
	double			pr;
	double			pi;
}					t_newt;

typedef struct		s_bshipdata
{
	int				fr;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	double			f[3];
	double			ph[3];
	double			w[3];
	double			c[3];
	int				change_phi;
	int				flag;
	int				maxiters;
	int				iters;
	double			pr;
	double			pi;
}					t_bship;

typedef struct		s_juliadata
{
	int				fr;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	int				maxiters;
	double			dx;
	double			dy;
	int				iters;
	double			pr;
	double			pi;
}					t_julia;

typedef struct		s_mandelbrotdata
{
	int				fr;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	int				x;
	int				y;
	int				maxiters;
	int				iters;
	double			pr;
	double			pi;
}					t_man;

typedef struct		s_fract
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				en;
	int				fr;
	int				flag;
	int				set[16];
	t_julia			*julia;
	t_man			*man;
	t_bship			*bship;
	t_newt			*newt;
}					t_main;

typedef struct		s_tf
{
	t_main			**fract;
	int				range;
}					t_tf;

void				init_newt(t_newt *newt);
void				init_bship(t_bship *bship);
void				init_mandel(t_man *man);
void				init_julia(t_main **fract);
void				ft_put_pixel(t_main *fract, int x, int y, int col);
void				draw_mendel(t_main *fract, int x, int y);
void				draw_julia(t_main *fract, int x, int y);
void				draw_bship(t_main *fract, int x, int y);
void				draw_newt(t_main *fract, int x, int y);
int					convert_color(int r, int g, int b);
void				create_threads(t_main **fract);
void				*calc(void *fract);
void				init_set_colors(t_main *fract);
int					light(t_main *fract);
int					convert_color(int r, int g, int b);
int					get_color(int i, t_main *fract);
void				loop_point(t_main *fract);
int					set_functions(int keykode, t_main **fract);
int					changeoldc(int x, int y, t_main **fract);
int					mouse(int keykode, int x, int y, t_main **fract);
int					zoom_center(int keykode, t_main *fract);
int					change_inter(int keykode, t_main *fract);
int					move_center(int keykode, t_main *fract);
int					change_fract(int keykode, t_main *fract);
int					exit_win(void *param);
int					close_win(int keykode, t_main *fract);
int					reset_data(t_main *fract);
int					jflag(t_main *fract);
void				ft_put_pixel(t_main *fract, int x, int y, int col);
int					usage(void);
int					check(char *n);
char				*name_win(int i);
void				ft_pp_bs_edition(t_main *fract, int x, int y, int col);
void				zoom_center_2(int keykode, t_main *fract, int zoom);
void				move_center_2(t_main *fract, double x_add, double y_add);

#endif
