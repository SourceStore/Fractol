/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:37:23 by rishchen          #+#    #+#             */
/*   Updated: 2017/04/28 17:38:48 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract.h"

/*
** minilibx/libmlx.a -o fract -lmlx -framework OpenGl -framework AppKit
*/

int				reset_data(t_main *fract)
{
	if (fract->fr == 1)
		init_julia(&fract);
	else if (fract->fr == 2)
		init_mandel(fract->man);
	else if (fract->fr == 3)
		init_bship(fract->bship);
	else
		init_newt(fract->newt);
	return (0);
}

/*
** Falg for change color in fractal burning ship
*/

int				jflag(t_main *fract)
{
	fract->flag *= -1;
	return (0);
}

/*
** Create a threads for every copy of struct for threads do not intersect in
*/

void			create_threads(t_main **fract)
{
	int			i;
	pthread_t	thrs[T];
	t_tf		p[T];

	i = -1;
	while (++i < T)
	{
		p[i].fract = fract;
		p[i].range = i * (H / T);
		if (pthread_create(&thrs[i], NULL, calc, (void *)&p[i]) != 0)
		{
			perror("Cannot create a thread");
			abort();
		}
	}
	i = -1;
	while (++i < T)
	{
		if (pthread_join(thrs[i], NULL) != 0)
		{
			perror("Cannot join a thread");
			abort();
		}
	}
}

/*
** Main point, where init all data, draw fract and start inf loop (loop_point)
*/

void			start_point(char **argv, int i)
{
	t_main		*fract;

	fract = (t_main *)malloc(sizeof(t_main));
	fract->julia = (t_julia *)malloc(sizeof(t_julia));
	fract->man = (t_man *)malloc(sizeof(t_man));
	fract->bship = (t_bship *)malloc(sizeof(t_bship));
	fract->newt = (t_newt *)malloc(sizeof(t_newt));
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, W, H, name_win(ft_atoi(argv[i])));
	fract->img = mlx_new_image(fract->mlx, W, H);
	fract->addr = mlx_get_data_addr(fract->img, &(fract->bpp),
									&(fract->sl), &(fract->en));
	fract->fr = ft_atoi(argv[i]);
	init_julia(&fract);
	init_mandel(fract->man);
	init_bship(fract->bship);
	init_newt(fract->newt);
	init_set_colors(fract);
	create_threads(&fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	loop_point(fract);
}

int				main(int argc, char **argv)
{
	pid_t		id;
	int			i;

	i = 0;
	if (argc <= 1 || argc > 6)
	{
		argc > 6 ? ft_putendl("Enter less 5 params") : 0;
		return (usage());
	}
	while (++i < argc)
	{
		if (!check(argv[i]))
			return (usage());
	}
	i = 0;
	while (++i < argc)
	{
		id = fork();
		if (id > 0)
			start_point(argv, i);
		else if (id < 0)
			return ((int)write(1, "Failed to fork\n", 15));
	}
	return (0);
}
