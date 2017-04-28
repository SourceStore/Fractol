/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:52:01 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/25 17:30:33 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

/*
** Zoom in point of corsore
*/

void		mouse_j(int keykode, int x, int y, t_main **fract)
{
	if (keykode == 4)
	{
		(*fract)->julia->zoom *= 1.2;
		(*fract)->julia->movex += (x - W / 2)
			/ (W * 2.5) / (*fract)->julia->zoom;
		(*fract)->julia->movey += (y - H / 2)
			/ (H * 2.5) / (*fract)->julia->zoom;
	}
	else if (keykode == 5)
	{
		(*fract)->julia->zoom /= 1.2;
		(*fract)->julia->movex -= (x - W / 2)
			/ (W * 2.5) / (*fract)->julia->zoom;
		(*fract)->julia->movey -= (y - H / 2)
			/ (H * 2.5) / (*fract)->julia->zoom;
	}
}

void		mouse_man(int keykode, int x, int y, t_main **fract)
{
	if (keykode == 4)
	{
		(*fract)->man->zoom *= 1.2;
		(*fract)->man->movex += (x - W / 2) / (W * 2.5) / (*fract)->man->zoom;
		(*fract)->man->movey += (y - H / 2) / (H * 2.5) / (*fract)->man->zoom;
	}
	else if (keykode == 5)
	{
		(*fract)->man->zoom /= 1.2;
		(*fract)->man->movex -= (x - W / 2) / (W * 2.5) / (*fract)->man->zoom;
		(*fract)->man->movey -= (y - H / 2) / (H * 2.5) / (*fract)->man->zoom;
	}
}

void		mouse_bs(int keykode, int x, int y, t_main **fract)
{
	if (keykode == 4)
	{
		(*fract)->bship->zoom *= 1.2;
		(*fract)->bship->movex += (x - W / 2) / (W * 2.5)
			/ (*fract)->bship->zoom;
		(*fract)->bship->movey += (y - H / 2) / (H * 2.5)
			/ (*fract)->bship->zoom;
	}
	else if (keykode == 5)
	{
		(*fract)->bship->zoom /= 1.2;
		(*fract)->bship->movex -= (x - W / 2) / (W * 2.5)
			/ (*fract)->bship->zoom;
		(*fract)->bship->movey -= (y - H / 2) / (H * 2.5)
			/ (*fract)->bship->zoom;
	}
}

void		mouse_newt(int keykode, int x, int y, t_main **fract)
{
	if (keykode == 4)
	{
		(*fract)->newt->zoom *= 1.2;
		(*fract)->newt->movex += (x - W / 2) / (W * 2.5) / (*fract)->newt->zoom;
		(*fract)->newt->movey += (y - H / 2) / (H * 2.5) / (*fract)->newt->zoom;
	}
	else if (keykode == 5)
	{
		(*fract)->newt->zoom /= 1.2;
		(*fract)->newt->movex -= (x - W / 2) / (W * 2.5) / (*fract)->newt->zoom;
		(*fract)->newt->movey -= (y - H / 2) / (H * 2.5) / (*fract)->newt->zoom;
	}
}

int			mouse(int keykode, int x, int y, t_main **fract)
{
	(*fract)->newt->z /= (keykode == 4 ? 1.2 : 0.8);
	if ((*fract)->fr == 1 && x < W && y < H)
		mouse_j(keykode, x, y, fract);
	else if ((*fract)->fr == 2 && x < W && y < H)
		mouse_man(keykode, x, y, fract);
	else if ((*fract)->fr == 3 && x < W && y < H)
		mouse_bs(keykode, x, y, fract);
	else if ((*fract)->fr == 4 && x < W && y < H)
		mouse_newt(keykode, x, y, fract);
	mlx_destroy_image((*fract)->mlx, (*fract)->img);
	mlx_clear_window((*fract)->mlx, (*fract)->win);
	(*fract)->img = mlx_new_image((*fract)->mlx, W, H);
	(*fract)->addr = mlx_get_data_addr((*fract)->img, &(*fract)->bpp,
			&(*fract)->sl, &(*fract)->en);
	create_threads(fract);
	mlx_put_image_to_window((*fract)->mlx, (*fract)->win, (*fract)->img, 0, 0);
	return (0);
}
