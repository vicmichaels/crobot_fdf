/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:03:49 by crobot            #+#    #+#             */
/*   Updated: 2021/11/26 14:03:51 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "../minilibx_macos/mlx.h"

/*
** window options
*/

# define WIDTH 				1440
# define HEIGHT 			1024
# define ZOOM 				5

/*
** key_codes
*/

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define NUM_2				84
# define NUM_4				86
# define NUM_6				88
# define NUM_8				91
# define NUM_PLUS			69
# define NUM_MINUS			78
# define SPACE_BAR			49
# define MAIN_ESC			53
# define MAIN_2				19
# define MAIN_4				21
# define MAIN_6				22
# define MAIN_8				28
# define MAIN_PLUS			24
# define MAIN_MINUS			27
# define W_KEY				13
# define A_KEY				0
# define S_KEY				1
# define D_KEY				2
# define Q_KEY				12
# define E_KEY				14

/*
** hex colours
*/

# define DARK		0x1e4775
# define BLUE		0x0167ae
# define LIGHT		0x99b5c7
# define WHITE		0xfdfaf3

typedef struct s_map
{
	int			fd;
	int			width;
	int			height;
	float		z_max;
	float		z_min;
}				t_map;

typedef struct s_ixyz
{
	int			x;
	int			y;
	int			z;
}				t_ixyz;

typedef struct s_fxyz
{
	float		x;
	float		y;
	float		z;
	int			colour;
}				t_fxyz;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	int			zoom;
	int			shift_x;
	int			shift_y;
	float		delta_x;
	float		delta_y;
	int			relief;
	int			iso_on;
	void		*img;
	char		*addr;
	double		angle;
	double		alpha;
	double		beta;
	double		gamma;
	long		offset;
	int			bpp;
	int			line_length;
	int			endian;
	t_map		*map;
	t_ixyz		**ixyz;
	t_fxyz		**fxyz;
}				t_fdf;

/*
** control
*/
int		close_fdf(t_fdf *fdf);
void	key_actions(t_fdf *fdf);
void	print_menu(t_fdf *fdf);
int		key_hook(int key, t_fdf *fdf);

/*
** customize
*/

void	translate(int key, t_fdf *fdf);
void	proj_switch(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	alt_rotate(int key, t_fdf *fdf);
void	zoom_custom(int key, t_fdf *fdf);
void	relief_custom(int key, t_fdf *fdf);

/*
** rotation
*/

void	rotation(t_fxyz *spin, t_fdf *fdf);
void	rotate_x(float *y, float *z, double alpha);
void	rotate_y(float *x, float *z, double beta);
void	rotate_z(float *x, float *y, double gamma);

/*
** read
*/

t_ixyz	**parse(char *line, t_fdf *fdf, int y);
t_ixyz	**mem_all(t_fdf *fdf);
t_ixyz	**read_map(char	*file, t_fdf *fdf);

/*
** param
*/

void	zoom(t_fxyz *a, t_fxyz *b, t_fdf *fdf);
void	param(t_fxyz *start, t_fxyz *finish, t_fdf *fdf);

/*
** math
*/

float	ft_abs(float num);
float	ft_max(float a, float b);
float	ft_min(float a, float b);
void	iso(float *x, float *y, float z, t_fdf *fdf);
void	find_delta(t_fdf *fdf, t_fxyz f_start, t_fxyz f_finish);

/*
** init
*/

int		open_file(const char *file);
t_map	*init_map(char *file);
t_fdf	*init_fdf(char *file);

/*
** draw
*/

t_fxyz	int_to_float(t_ixyz ixyz);
void	pixel_put(t_fdf *fdf, int x, int y, int colour);
void	line(t_ixyz i_start, t_ixyz i_finish, t_fdf *fdf);
void	draw(t_fdf *fdf);

/*
** colour
*/

void	background(t_fdf *fdf);
double	percent(float start, float end, float tmp);
int		formula(int start, int finish, double p);
int		dye(float z, t_map *map);
int		gradient(t_fxyz tmp, t_fxyz start, t_fxyz finish, t_fdf *fdf);

/*
** fdf
*/

int		main(int ac, char **av);

#endif
