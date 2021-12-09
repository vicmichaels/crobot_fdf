/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:06:23 by crobot            #+#    #+#             */
/*   Updated: 2021/11/30 22:06:28 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotate_x(float *y, float *z, double alpha)
{
	float	tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(alpha) + *z * sin(alpha);
	*z = -tmp_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, float *z, double beta)
{
	float	tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(beta) + *z * sin(beta);
	*z = -tmp_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, double gamma)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(gamma) - tmp_y * sin(gamma);
	*y = tmp_x * sin(gamma) + tmp_y * cos(gamma);
}

void	rotation(t_fxyz *spin, t_fdf *fdf)
{
	rotate_x(&spin->y, &spin->z, fdf->alpha);
	rotate_y(&spin->x, &spin->z, fdf->beta);
	rotate_z(&spin->x, &spin->y, fdf->gamma);
}
