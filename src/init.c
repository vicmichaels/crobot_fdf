/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:25:46 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:25:48 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("FILE ERROR...\n");
		exit (0);
	}
	return (fd);
}

t_map	*init_map(char *file)
{
	t_map	*map;
	char	*line;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->fd = open_file(file);
	map->width = 0;
	map->height = 0;
	line = get_next_line(map->fd);
	while (line)
	{
		if (map->height == 0)
			map->width = count_words(line, ' ');
		map->height++;
		free(line);
		line = get_next_line(map->fd);
	}
	free(line);
	return (map);
}

t_fdf	*init_fdf(char *file)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->map = init_map(file);
	fdf->ixyz = read_map(file, fdf);
	fdf->zoom = ZOOM;
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp),
			&(fdf->line_length), &(fdf->endian));
	fdf->relief = 1;
	fdf->shift_x = WIDTH / 3;
	fdf->shift_y = HEIGHT / 3;
	fdf->iso_on = 1;
	fdf->angle = 0.523599;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	return (fdf);
}
