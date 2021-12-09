/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:25:15 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:25:18 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	pixel_put(t_fdf *fdf, int x, int y, int colour)
{
	fdf->offset = (x * fdf->bpp / 8) + (y * fdf->line_length);
	if (x < WIDTH && y >= 0 && y < HEIGHT)
	{
		fdf->addr[fdf->offset] = colour;
		fdf->addr[++fdf->offset] = colour >> 8;
		fdf->addr[++fdf->offset] = colour >> 16;
	}
}

t_fxyz	int_to_float(t_ixyz ixyz)
{
	t_fxyz	fxyz;

	fxyz.x = (float)ixyz.x;
	fxyz.y = (float)ixyz.y;
	fxyz.z = (float)ixyz.z;
	return (fxyz);
}

void	line(t_ixyz i_start, t_ixyz i_finish, t_fdf *fdf)
{
	t_fxyz	f_start;
	t_fxyz	f_finish;
	t_fxyz	tmp;

	f_start = int_to_float(i_start);
	f_finish = int_to_float(i_finish);
	param(&f_start, &f_finish, fdf);
	find_delta(fdf, f_start, f_finish);
	tmp = f_start;
	while ((int)(tmp.x - f_finish.x) || (int)(tmp.y - f_finish.y))
	{
		tmp.colour = gradient(tmp, f_start, f_finish, fdf);
		pixel_put(fdf, tmp.x, tmp.y, tmp.colour);
		tmp.x += fdf->delta_x;
		tmp.y += fdf->delta_y;
		if (tmp.x > WIDTH || tmp.y > HEIGHT || tmp.x < 0
			|| tmp.y < 0)
			break ;
	}
}

void	draw(t_fdf *fdf)
{
	int		y;
	int		x;

	y = 0;
	background(fdf);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (y < fdf->map->height - 1)
				line(fdf->ixyz[y][x], fdf->ixyz[y + 1][x], fdf);
			if (x < fdf->map->width - 1)
				line(fdf->ixyz[y][x], fdf->ixyz[y][x + 1], fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_menu(fdf);
}
