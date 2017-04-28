/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:18:33 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/25 18:23:47 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

/*
** Change state of present fractal
*/

int			change_fract(int keykode, t_main *fract)
{
	if (keykode == 18)
		fract->fr = 1;
	else if (keykode == 19)
		fract->fr = 2;
	else if (keykode == 20)
		fract->fr = 3;
	else if (keykode == 21)
		fract->fr = 4;
	return (0);
}

int			move_center(int keykode, t_main *fract)
{
	double	x_add;
	double	y_add;

	if (keykode == 125 || keykode == 126)
		y_add = keykode == 125 ? -0.3 : 0.3;
	if (keykode == 123 || keykode == 124)
		x_add = keykode == 124 ? -0.3 : 0.3;
	if (fract->fr == 1)
	{
		fract->julia->movex += x_add / fract->julia->zoom;
		fract->julia->movey += y_add / fract->julia->zoom;
	}
	else if (fract->fr == 2)
	{
		fract->man->movex += x_add / fract->man->zoom;
		fract->man->movey += y_add / fract->man->zoom;
	}
	else if (fract->fr >= 3)
		move_center_2(fract, x_add, y_add);
	return (0);
}

void		move_center_2(t_main *fract, double x_add, double y_add)
{
	if (fract->fr == 3)
	{
		fract->bship->movex += x_add / fract->bship->zoom;
		fract->bship->movey += y_add / fract->bship->zoom;
	}
	else if (fract->fr == 4)
	{
		fract->newt->movex += x_add / fract->newt->zoom;
		fract->newt->movey += y_add / fract->newt->zoom;
	}
}

int			change_inter(int keykode, t_main *fract)
{
	double	iter;

	iter = keykode == 24 ? 50 : -50;
	if (fract->fr == 1)
	{
		if ((fract->julia->maxiters + iter != 0))
			fract->julia->maxiters += iter;
	}
	else if (fract->fr == 2)
	{
		if (fract->man->maxiters + iter != 0)
			fract->man->maxiters += iter;
	}
	else if (fract->fr == 3)
	{
		if (fract->bship->maxiters + iter != 0)
			fract->bship->maxiters += iter;
	}
	else if (fract->fr == 4)
	{
		if (fract->newt->maxiters + iter != 0)
			fract->newt->maxiters += iter;
	}
	return (0);
}

/*
**Function for Julia- change center and redraw, while change position of mouse
*/

int			changeoldc(int x, int y, t_main **fract)
{
	if ((*fract)->fr == 1 && (*fract)->flag == 1
		&& x <= W && x >= 0 && y <= W && y >= 0)
	{
		(*fract)->julia->cre = (x - W) / (W * 1.5) / (*fract)->julia->zoom;
		(*fract)->julia->cim = (y - H) / (H * 1.5) / (*fract)->julia->zoom;
		mlx_destroy_image((*fract)->mlx, (*fract)->img);
		mlx_clear_window((*fract)->mlx, (*fract)->win);
		(*fract)->img = mlx_new_image((*fract)->mlx, W, H);
		(*fract)->addr = mlx_get_data_addr((*fract)->img, &(*fract)->bpp,
				&(*fract)->sl, &(*fract)->en);
		create_threads(fract);
		mlx_put_image_to_window((*fract)->mlx,
								(*fract)->win, (*fract)->img, 0, 0);
	}
	return (0);
}
