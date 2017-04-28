/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:29:00 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/24 16:34:03 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

int			close_win(int keykode, t_main *fract)
{
	if (keykode == 53 || keykode == 65307)
	{
		ft_memdel(&fract->mlx);
		ft_memdel((void **)&fract->addr);
		ft_memdel(&fract->img);
		ft_memdel(&fract->mlx);
		free(fract);
		fract = NULL;
		exit(0);
	}
	return (0);
}

int			exit_win(void *param)
{
	param = NULL;
	exit(0);
	return (0);
}

int			usage(void)
{
	ft_putendl(
			"[1] - for Julia\'s set, [2] - for Mandelbrot set, "
			"[3] - for Burning ship set, [4] - for Newton set");
	return (0);
}

int			check(char *n)
{
	int		r;

	r = ft_atoi(n);
	if (r < 1 || r > 4)
		return (0);
	else
		return (r);
}

char		*name_win(int i)
{
	char	*s_1;
	char	*s_2;
	char	*s_3;
	char	*s_4;

	s_1 = "Fract'ol Julia set";
	s_2 = "Fract'ol Mandelbrot set";
	s_3 = "Fract'ol Burning ship set";
	s_4 = "Fract'ol Newton set";
	if (i == 1)
		return (s_1);
	else if (i == 2)
		return (s_2);
	else if (i == 3)
		return (s_3);
	else
		return (s_4);
}
