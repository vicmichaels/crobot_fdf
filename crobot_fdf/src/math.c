/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:26:48 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:26:50 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (num * (-1));
	else
		return (num);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	find_delta(t_fdf *fdf, t_fxyz f_start, t_fxyz f_finish)
{
	float	max;

	fdf->delta_x = f_finish.x - f_start.x;
	fdf->delta_y = f_finish.y - f_start.y;
	max = ft_max(ft_abs(fdf->delta_x), ft_abs(fdf->delta_y));
	fdf->delta_x /= max;
	fdf->delta_y /= max;
}

void	iso(float *x, float *y, float z, t_fdf *fdf)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(fdf->angle);
	*y = (tmp_x + tmp_y) * sin(fdf->angle) - z;
}
