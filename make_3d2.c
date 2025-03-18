/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3d2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:56:44 by mboumlik          #+#    #+#             */
/*   Updated: 2025/03/18 13:53:45 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	calculate_perp_dist(t_cube *data, double x1, double y1)
{
	double	wall_x;
	double	wall_y;

	if (data->d_side == 0)
	{
		if (data->d_step_x < 0)
			wall_x = data->d_map_x + 1;
		else
			wall_x = data->d_map_x;
		data->perp_wall_dist = (wall_x - x1 / 64.0) / data->d_ray_dir_x;
	}
	else
	{
		if (data->d_step_y < 0)
			wall_y = data->d_map_y + 1;
		else
			wall_y = data->d_map_y;
		data->perp_wall_dist = (wall_y - y1 / 64.0) / data->d_ray_dir_y;
	}
}

void	put_image_whit_dark(t_cube *data, int x, int y)
{
	int	r;
	int	g;
	int	b;
	int	floor_color;

	floor_color = data->var.f[0] << 16 | (data->var.f[1] << 8) | data->var.f[2];
	r = ((floor_color >> 16) & 0xFF);
	g = ((floor_color >> 8) & 0xFF);
	b = (floor_color & 0xFF);
	my_mlx_pixel_put2(&data->render_img, x, y, (r << 16) | (g << 8) | b);
}

void	draw_vertical_line(t_cube *data, int x)
{
	double	wall_top;
	double	wall_bottom;

	wall_top = (SCREEN_HEIGHT / 2) - (data->var.line_height / 2);
	wall_bottom = (SCREEN_HEIGHT / 2) + (data->var.line_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	if (wall_bottom >= SCREEN_HEIGHT)
		wall_bottom = SCREEN_HEIGHT - 1;
	draw_sky(data, wall_top, x);
	draw_walls(data, wall_top, wall_bottom, x);
	draw_flower(data, wall_bottom, x);
}
