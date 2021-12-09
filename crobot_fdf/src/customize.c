/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:50:48 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:50:51 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	relief_custom(int key, t_fdf *fdf)
{
	if (key == NUM_2 || key == MAIN_2)
		fdf->relief -= 1;
	else if (key == NUM_8 || key == MAIN_8)
		fdf->relief += 1;
	if (fdf->relief < 1)
		fdf->relief = 1;
	else if (fdf->relief > 100)
		fdf->relief = 100;
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == W_KEY)
		fdf->alpha += 0.03;
	else if (key == S_KEY)
		fdf->alpha -= 0.03;
	else if (key == A_KEY)
		fdf->beta += 0.03;
	else if (key == D_KEY)
		fdf->beta -= 0.03;
	else if (key == Q_KEY)
		fdf->gamma += 0.03;
	else if (key == E_KEY)
		fdf->gamma -= 0.03;
}

void	alt_rotate(int key, t_fdf *fdf)
{
	if (key == NUM_4 || key == MAIN_4)
		fdf->angle -= 0.03;
	if (key == NUM_6 || key == MAIN_6)
		fdf->angle += 0.03;
}

void	proj_switch(int key, t_fdf *fdf)
{
	double	alpha;
	double	beta;
	double	gamma;

	alpha = fdf->alpha;
	beta = fdf->beta;
	gamma = fdf->gamma;
	if (key == SPACE_BAR)
	{
		if (fdf->iso_on == 1)
		{
			fdf->iso_on = 0;
			fdf->alpha = 0;
			fdf->beta = 0;
			fdf->gamma = 0;
		}
		else if (fdf->iso_on == 0)
		{
			fdf->iso_on = 1;
			fdf->alpha = alpha;
			fdf->beta = beta;
			fdf->gamma = gamma;
		}
	}
}

void	translate(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->shift_x -= 10;
	else if (key == ARROW_RIGHT)
		fdf->shift_x += 10;
	else if (key == ARROW_UP)
		fdf->shift_y -= 10;
	else
		fdf->shift_y += 10;
}
