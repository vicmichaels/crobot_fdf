/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:24:53 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:24:56 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_fdf(t_fdf *fdf)
{
	int	i;

	i = -1;
	free(fdf);
	free(fdf->map);
	while (fdf->ixyz[++i] != NULL)
		free(fdf->ixyz[i]);
	free(fdf->ixyz);
	exit(0);
}

void	print_menu(t_fdf *fdf)
{
	char	*menu;
	int		text;

	text = 0xdc251e;
	menu = "press arrows to translate";
	mlx_string_put(fdf->mlx, fdf->win, 10, 5, text, menu);
	menu = "press space to switch 3d/2d";
	mlx_string_put(fdf->mlx, fdf->win, 10, 20, text, menu);
	menu = "press 8/2 to customize relief";
	mlx_string_put(fdf->mlx, fdf->win, 10, 35, text, menu);
	menu = "press +/- to zoom in/zoom out";
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, text, menu);
	menu = "press W A S D Q E to rotate";
	mlx_string_put(fdf->mlx, fdf->win, 10, 65, text, menu);
	menu = "press 4/6 to distort object";
	mlx_string_put(fdf->mlx, fdf->win, 10, 80, text, menu);
}

int	key_hook(int key, t_fdf *fdf)
{
	if (key == MAIN_ESC)
		close_fdf(fdf);
	else if (key == NUM_MINUS || key == MAIN_MINUS
		|| key == NUM_PLUS || key == MAIN_PLUS)
		zoom_custom(key, fdf);
	else if (key == NUM_2 || key == MAIN_2
		|| key == NUM_8 || key == MAIN_8)
		relief_custom(key, fdf);
	else if (key == NUM_4 || key == MAIN_4
		|| key == NUM_6 || key == MAIN_6)
		alt_rotate(key, fdf);
	else if (key == W_KEY || key == A_KEY || key == S_KEY
		|| key == D_KEY || key == Q_KEY || key == E_KEY)
		rotate(key, fdf);
	else if (key == SPACE_BAR)
		proj_switch(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		translate(key, fdf);
	draw(fdf);
	return (0);
}

void	key_actions(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_hook, fdf);
}
