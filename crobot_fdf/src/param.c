/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:26:58 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:27:00 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_fxyz *a, t_fxyz *b, t_fdf *fdf)
{
	a->x *= (float)fdf->zoom;
	a->y *= (float)fdf->zoom;
	b->x *= (float)fdf->zoom;
	b->y *= (float)fdf->zoom;
	a->z *= (float)fdf->relief;
	b->z *= (float)fdf->relief;
}

void	zoom_custom(int key, t_fdf *fdf)
{
	if (key == NUM_PLUS || key == MAIN_PLUS)
		fdf->zoom += 1;
	else if (key == NUM_MINUS || key == MAIN_MINUS)
		fdf->zoom -= 1;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
}

void	param(t_fxyz *start, t_fxyz *finish, t_fdf *fdf)
{
	start->colour = dye(start->z, fdf->map);
	zoom(start, finish, fdf);
	rotation(start, fdf);
	rotation(finish, fdf);
	if (fdf->iso_on)
	{
		iso(&start->x, &start->y, start->z, fdf);
		iso(&finish->x, &finish->y, finish->z, fdf);
	}
	start->x += fdf->shift_x;
	start->y += fdf->shift_y;
	finish->x += fdf->shift_x;
	finish->y += fdf->shift_y;
}
