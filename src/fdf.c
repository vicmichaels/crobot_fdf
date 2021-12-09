/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:25:35 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:25:37 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf = init_fdf(av[1]);
		draw(fdf);
		key_actions(fdf);
		mlx_loop(fdf->mlx);
	}
	ft_printf("FEED FDF A SINGLE FILE...\n");
	return (0);
}
