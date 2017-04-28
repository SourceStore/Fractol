/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fracts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:31:05 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/22 17:31:09 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

void	init_julia(t_main **fract)
{
	(*fract)->flag = -1;
	(*fract)->julia->fr = 1;
	(*fract)->julia->maxiters = 100;
	(*fract)->julia->cre = -0.7;
	(*fract)->julia->cim = 0.27015;
	(*fract)->julia->zoom = 0.6;
	(*fract)->julia->movex = 0;
	(*fract)->julia->movey = 0;
}

void	init_mandel(t_man *man)
{
	man->fr = 2;
	man->maxiters = 50;
	man->zoom = 0.6;
	man->movex = -0.7;
	man->movey = 0;
}

void	init_bship(t_bship *bship)
{
	int	i;

	i = -1;
	bship->fr = 3;
	bship->maxiters = 100;
	bship->zoom = 0.6;
	bship->movex = -0.5;
	bship->movey = -0.5;
	bship->flag = 2;
	bship->change_phi = 1;
	while (++i < 3)
	{
		bship->f[i] = 20 + 20 * i;
		bship->w[i] = 235 - 20 * i;
		bship->c[i] = 20 + 20 * i;
	}
	bship->ph[0] = 3;
	bship->ph[1] = 2;
	bship->ph[2] = 0;
}

void	init_newt(t_newt *newt)
{
	int	i;

	i = -1;
	newt->z = 0.4;
	newt->dx = 1 / (2 * 0.4);
	newt->dy = 1 / (2 * 0.4);
	newt->fr = 4;
	newt->maxiters = 100;
	newt->zoom = 0.6;
	newt->movex = -0.5;
	newt->movey = -0.5;
	newt->flag = 0;
	newt->change_phi = -1;
	while (++i < 3)
	{
		newt->f[i] = 0.24;
		newt->w[i] = 65;
		newt->c[i] = 190;
	}
	newt->ph[0] = 4.5;
	newt->ph[1] = 2.5;
	newt->ph[2] = 0;
}
