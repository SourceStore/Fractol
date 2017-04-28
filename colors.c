/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:33:56 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/22 17:33:59 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

void		init_set_colors(t_main *fract)
{
	fract->set[0] = convert_color(0, 0, 0);
	fract->set[1] = convert_color(25, 7, 26);
	fract->set[2] = convert_color(9, 1, 47);
	fract->set[3] = convert_color(4, 4, 73);
	fract->set[4] = convert_color(0, 7, 100);
	fract->set[5] = convert_color(12, 44, 138);
	fract->set[6] = convert_color(24, 82, 177);
	fract->set[7] = convert_color(57, 125, 209);
	fract->set[8] = convert_color(134, 181, 229);
	fract->set[9] = convert_color(211, 236, 248);
	fract->set[10] = convert_color(241, 233, 191);
	fract->set[11] = convert_color(248, 201, 95);
	fract->set[12] = convert_color(255, 170, 0);
	fract->set[13] = convert_color(204, 128, 0);
	fract->set[14] = convert_color(153, 87, 0);
	fract->set[15] = convert_color(106, 52, 3);
}

int			convert_color(int r, int g, int b)
{
	return ((int)(r * SQRT(256) + g * 256 + b));
}

int			get_color(int i, t_main *fract)
{
	i = i % 16;
	return (fract->set[i]);
}

int			light(t_main *fract)
{
	if (fract->bship->flag > 1)
		fract->bship->change_phi = -1;
	if (fract->bship->flag < -1)
		fract->bship->change_phi = 1;
	fract->bship->flag += fract->bship->change_phi;
	return (0);
}
