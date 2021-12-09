/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:13:57 by crobot            #+#    #+#             */
/*   Updated: 2021/11/30 22:14:01 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	background(t_fdf *fdf)
{
	int		i;
	int		*img;

	i = 0;
	ft_bzero(fdf->addr, WIDTH * HEIGHT * (fdf->bpp / 8));
	img = (int *)(fdf->addr);
	while (i < HEIGHT * WIDTH)
	{
		img[i] = 0x2b211f;
		i++;
		img[i] = 0x1a1915;
		i++;
	}
}

double	percent(float start, float end, float tmp)
{
	double	pos;
	double	len;

	pos = tmp - start;
	len = end - start;
	if (len == 0)
		return (1);
	return (pos / len);
}

int	dye(float z, t_map *map)
{
	double	p;

	p = percent(map->z_min, map->z_max, z);
	if (p < 0.25)
		return (DARK);
	else if (p < 0.5)
		return (BLUE);
	else if (p < 0.75)
		return (LIGHT);
	else
		return (WHITE);
}

int	formula(int start, int finish, double p)
{
	return ((int)((1 - p) * start + p * finish));
}

int	gradient(t_fxyz tmp, t_fxyz start, t_fxyz finish, t_fdf *fdf)
{
	int		r;
	int		g;
	int		b;
	double	p;

	if (tmp.z == finish.z)
		return (tmp.colour);
	if (fdf->delta_x > fdf->delta_y)
		p = percent(start.x, finish.x, tmp.x);
	else
		p = percent(start.y, finish.y, tmp.y);
	r = formula((start.colour >> 16) & 0xFF,
			(finish.colour >> 16) & 0xFF, p);
	g = formula((start.colour >> 8) & 0xFF,
			(finish.colour >> 8) & 0xFF, p);
	b = formula(start.colour & 0xFF,
			finish.colour & 0xFF, p);
	return ((r << 16) | (g << 8) | b);
}
