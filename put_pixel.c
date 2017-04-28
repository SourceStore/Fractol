/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:51:03 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/25 17:39:26 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

void			ft_put_pixel(t_main *fract, int x, int y, int col)
{
	if (fract->fr <= 2 || fract->fr == 4)
	{
		if (x >= 0 && y >= 0 && x < W && y < H)
		{
			fract->addr[x * 4 + fract->sl * y] = (unsigned char)(col & 255);
			fract->addr[x * 4 + 1 + fract->sl * y] =
										(unsigned char)((col >> 8) & 255);
			fract->addr[x * 4 + 2 + fract->sl * y] =
										(unsigned char)((col >> 16) & 255);
		}
	}
	else
	{
		if (x >= 0 && y >= 0 && x < W && y < H)
			ft_pp_bs_edition(fract, x, y, col);
	}
}

void			ft_pp_bs_edition(t_main *fract, int x, int y, int col)
{
	double		freq;

	freq = M_PI * 2 / fract->bship->maxiters;
	fract->addr[x * 4 + fract->sl * y] =
			(unsigned char)(sin(freq * col - 4 +
								fract->bship->ph[fract->bship->flag]) *
							fract->bship->w[0] + fract->bship->c[0]);
	fract->addr[x * 4 + 1 + fract->sl * y] = (unsigned char)(sin(freq * col - 2
				+ fract->bship->ph[fract->bship->flag])
					* fract->bship->w[0] + fract->bship->c[0]);
	fract->addr[x * 4 + 2 + fract->sl * y] = (unsigned char)(sin(freq * col - 1
				+ fract->bship->ph[fract->bship->flag])
					* fract->bship->w[0] + fract->bship->c[0]);
}

/*
** Zoom in middle of screen
*/

int				zoom_center(int keykode, t_main *fract)
{
	double		zoom;

	zoom = 1.25;
	if (fract->fr == 1)
	{
		if (keykode == 69)
			fract->julia->zoom *= zoom;
		else
			fract->julia->zoom /= zoom;
	}
	else if (fract->fr == 2)
	{
		if (keykode == 69)
			fract->man->zoom *= zoom;
		else
			fract->man->zoom /= zoom;
	}
	else if (fract->fr >= 3)
		zoom_center_2(keykode, fract, zoom);
	return (0);
}

void			zoom_center_2(int keykode, t_main *fract, int zoom)
{
	if (fract->fr == 3)
	{
		if (keykode == 69)
			fract->bship->zoom *= zoom;
		else
			fract->bship->zoom /= zoom;
	}
	else if (fract->fr == 4)
	{
		if (keykode == 69)
			fract->newt->zoom *= zoom;
		else
			fract->newt->zoom /= zoom;
	}
}
