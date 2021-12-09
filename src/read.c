/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:43:16 by crobot            #+#    #+#             */
/*   Updated: 2021/11/09 11:43:50 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_ixyz	**parse(char *line, t_fdf *fdf, int y)
{
	int		x;
	char	**z_val;

	x = 0;
	z_val = ft_split(line, ' ');
	while (z_val[x])
	{
		fdf->ixyz[y][x].z = ft_atoi(z_val[x]);
		fdf->ixyz[y][x].x = x;
		fdf->ixyz[y][x].y = y;
		if (fdf->ixyz[y][x].z > fdf->map->z_max)
			fdf->map->z_max = fdf->ixyz[y][x].z;
		if (fdf->ixyz[y][x].z < fdf->map->z_min && fdf->map->z_min > 0)
			fdf->map->z_max = fdf->ixyz[y][x].z;
		free(z_val[x++]);
	}
	free(z_val);
	free(line);
	return (fdf->ixyz);
}

t_ixyz	**mem_all(t_fdf	*fdf)
{
	int		x;

	fdf->ixyz = (t_ixyz **)malloc(sizeof(t_ixyz *) * (fdf->map->height + 1));
	if (!fdf->ixyz)
		return (NULL);
	x = -1;
	while (++x < fdf->map->height)
		fdf->ixyz[x] = (t_ixyz *)malloc(sizeof(t_ixyz) * (fdf->map->width + 1));
	return (fdf->ixyz);
}

t_ixyz	**read_map(char	*file, t_fdf *fdf)
{
	char	*line;
	int		y;

	fdf->ixyz = mem_all(fdf);
	fdf->map->fd = open_file(file);
	y = 0;
	line = get_next_line(fdf->map->fd);
	while (line)
	{
		fdf->ixyz = parse(line, fdf, y);
		y++;
		line = get_next_line(fdf->map->fd);
	}
	fdf->ixyz[y] = NULL;
	close(fdf->map->fd);
	free(line);
	return (fdf->ixyz);
}
