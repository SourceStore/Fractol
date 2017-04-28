/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:09:04 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/22 18:13:37 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

/*
** Main function for calculate every pixel for fractal (used in threads)
*/

void		*calc(void *p)
{
	int		x;
	int		area;
	t_tf	*tempf;

	tempf = (t_tf *)p;
	area = tempf->range + H / T;
	while (tempf->range < area)
	{
		x = -1;
		while (++x < W)
		{
			if ((*(tempf->fract))->fr == 1)
				draw_julia((*tempf->fract), x, tempf->range);
			else if ((*(tempf->fract))->fr == 2)
				draw_mendel((*tempf->fract), x, tempf->range);
			else if ((*(tempf->fract))->fr == 3)
				draw_bship((*tempf->fract), x, tempf->range);
			else
				draw_newt((*tempf->fract), x, tempf->range);
		}
		tempf->range++;
	}
	pthread_exit(NULL);
}

/*
** Function for processing pushed button (change fractal) then redraw
*/

int			set_functions(int keykode, t_main **fract)
{
	if (keykode == 53 || keykode == 65307)
		close_win(keykode, *fract);
	if (keykode == 125 || keykode == 126 || keykode == 123 || keykode == 124)
		move_center(keykode, *fract);
	if (keykode == 24 || keykode == 27)
		change_inter(keykode, *fract);
	if (keykode == 69 || keykode == 78)
		zoom_center(keykode, *fract);
	if (keykode == 18 || keykode == 19 || keykode == 20 || keykode == 21)
		change_fract(keykode, *fract);
	if (keykode == 15)
		reset_data(*fract);
	if (keykode == 256)
		jflag(*fract);
	if (keykode == 49)
		light(*fract);
	mlx_destroy_image((*fract)->mlx, (*fract)->img);
	mlx_clear_window((*fract)->mlx, (*fract)->win);
	(*fract)->img = mlx_new_image((*fract)->mlx, W, H);
	(*fract)->addr = mlx_get_data_addr((*fract)->img, &(*fract)->bpp,
			&(*fract)->sl, &(*fract)->en);
	create_threads(fract);
	mlx_put_image_to_window((*fract)->mlx, (*fract)->win, (*fract)->img, 0, 0);
	return (0);
}

void		loop_point(t_main *fract)
{
	mlx_hook(fract->win, 17, 0, &exit_win, fract);
	mlx_hook(fract->win, 2, 1 << 7, set_functions, &fract);
	mlx_hook(fract->win, 6, 0, changeoldc, &fract);
	mlx_mouse_hook(fract->win, mouse, &fract);
	mlx_loop(fract->mlx);
}
