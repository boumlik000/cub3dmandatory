/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3d1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:46:04 by mboumlik          #+#    #+#             */
/*   Updated: 2025/03/18 13:52:54 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	init_ray_values(t_cube *data, double x1, double y1, double angle)
{
	data->d_rad = angle * M_PI / 180.0;
	data->d_ray_dir_x = cos(data->d_rad);
	data->d_ray_dir_y = sin(data->d_rad);
	data->d_map_x = (int)(x1 / 64);
	data->d_map_y = (int)(y1 / 64);
	data->d_delta_dist_x = fabs(1.0 / data->d_ray_dir_x);
	data->d_delta_dist_y = fabs(1.0 / data->d_ray_dir_y);
}

// Calculate step and side distances
void	calculate_step_dist(t_cube *data, double x1)
{
	if (data->d_ray_dir_x < 0)
	{
		data->d_step_x = -1;
		data->d_side_dist_x = ((x1 / 64.0) - data->d_map_x)
			* data->d_delta_dist_x;
	}
	else
	{
		data->d_step_x = 1;
		data->d_side_dist_x = (data->d_map_x + 1.0 - (x1 / 64.0))
			* data->d_delta_dist_x;
	}
}

void	calculate_step_dist_y(t_cube *data, double y1)
{
	if (data->d_ray_dir_y < 0)
	{
		data->d_step_y = -1;
		data->d_side_dist_y = ((y1 / 64.0) - data->d_map_y)
			* data->d_delta_dist_y;
	}
	else
	{
		data->d_step_y = 1;
		data->d_side_dist_y = (data->d_map_y + 1.0 - (y1 / 64.0))
			* data->d_delta_dist_y;
	}
}

void	my_mlx_pixel_put2(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
