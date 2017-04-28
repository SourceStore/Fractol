/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:56:58 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/22 18:03:40 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

void		draw_newt(t_main *fract, int x, int y)
{
	double	tmp;
	int		n;
	t_newt	nt;

	nt.newre = (x - W / 2) / (0.5 * fract->newt->zoom * W) + fract->newt->movex;
	nt.newim = (y - H / 2) / (0.5 * fract->newt->zoom * H) + fract->newt->movey;
	n = -1;
	tmp = 1.0;
	while (tmp > 0.0000001 && ++n < fract->newt->maxiters)
	{
		nt.oldre = nt.newre;
		nt.oldim = nt.newim;
		tmp = (SQRT(nt.newre) + SQRT(nt.newim)) *
				(SQRT(nt.newre) + SQRT(nt.newim));
		nt.newre = (2 * nt.newre * tmp + SQRT(nt.newre) -
					SQRT(nt.newim)) / (3.0 * tmp);
		nt.newim = (2 * nt.newim * (tmp - nt.oldre)) / (3.0 * tmp);
		tmp = (nt.newre - nt.oldre) * (nt.newre - nt.oldre)
			+ (nt.newim - nt.oldim) * (nt.newim - nt.oldim);
	}
	if (n < fract->newt->maxiters)
		n = get_color(n, fract);
	ft_put_pixel(fract, x, y, n);
}

void		draw_mendel(t_main *fract, int x, int y)
{
	int		n;
	t_man	m;

	m.cre = (x - W / 2) / (0.5 * fract->man->zoom * W) + fract->man->movex;
	m.cim = (y - H / 2) / (0.5 * fract->man->zoom * H) + fract->man->movey;
	n = -1;
	m.newre = 0;
	m.newim = 0;
	m.oldre = 0;
	m.oldim = 0;
	while (++n < fract->man->maxiters)
	{
		m.oldre = m.newre;
		m.oldim = m.newim;
		m.newre = SQRT(m.newre) - SQRT(m.oldim) + m.cre;
		m.newim = 2 * m.oldre * m.oldim + m.cim;
		if (SQRT(m.newre) + SQRT(m.newim) > 4)
			break ;
	}
	if (n < fract->man->maxiters)
		n = get_color(n, fract);
	ft_put_pixel(fract, x, y, n);
}

void		draw_julia(t_main *fract, int x, int y)
{
	int		n;
	t_julia	jul;

	jul.newre = (x - W / 2) / (0.5 * fract->julia->zoom * W)
				+ fract->julia->movex;
	jul.newim = (y - H / 2) / (0.5 * fract->julia->zoom * H)
				+ fract->julia->movey;
	n = -1;
	while (++n < fract->julia->maxiters)
	{
		jul.oldre = jul.newre;
		jul.oldim = jul.newim;
		jul.newre = SQRT(jul.oldre) - SQRT(jul.oldim) + fract->julia->cre;
		jul.newim = 2 * jul.oldre * jul.oldim + fract->julia->cim;
		if (SQRT(jul.newre) + SQRT(jul.newim) > 4)
			break ;
		n++;
	}
	if (n < fract->julia->maxiters)
		n = get_color(n, fract);
	else
		n = 0;
	ft_put_pixel(fract, x, y, n);
}

void		draw_bship(t_main *fract, int x, int y)
{
	int		n;
	t_bship	bs;

	bs.pr = (x - W / 2) / (0.5 * fract->bship->zoom * W) + fract->bship->movex;
	bs.pi = (y - H / 2) / (0.5 * fract->bship->zoom * H) + fract->bship->movey;
	bs.newre = bs.pr;
	bs.newim = bs.pi;
	bs.oldim = 0;
	bs.oldre = 0;
	n = -1;
	while (++n < fract->bship->maxiters)
	{
		bs.newre = SQRT(bs.oldre) - SQRT(bs.oldim) + bs.pr;
		bs.newim = 2 * fabs(bs.oldre * bs.oldim) + bs.pi;
		bs.oldim = bs.newim;
		bs.oldre = bs.newre;
		if (SQRT(bs.newre) + SQRT(bs.newim) > 4)
			break ;
	}
	ft_put_pixel(fract, x, y, n);
}
