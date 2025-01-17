/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3d2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:56:44 by mboumlik          #+#    #+#             */
/*   Updated: 2025/01/17 13:59:20 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// Calculate perpendicular wall distance
void	calculate_perp_dist(t_cube *data, double x1, double y1)
{
	if (data->d_side == 0)
		data->perp_wall_dist = ((data->d_map_x - x1 / 64.0 + (1
						- data->d_step_x) / 2) / data->d_ray_dir_x);
	else
		data->perp_wall_dist = ((data->d_map_y - y1 / 64.0 + (1
						- data->d_step_y) / 2) / data->d_ray_dir_y);
}

void	put_image_whit_dark(t_cube *data, double darkness, int x, int y)
{
	int	r;
	int	g;
	int	b;
	int	floor_color;

	floor_color = data->var.c[0] << 16 | (data->var.c[1] << 8) | data->var.c[2];
	r = ((floor_color >> 16) & 0xFF) * (1.0 - darkness);
	g = ((floor_color >> 8) & 0xFF) * (1.0 - darkness);
	b = (floor_color & 0xFF) * (1.0 - darkness);
	my_mlx_pixel_put2(&data->render_img, x, y, (r << 16) | (g << 8) | b);
}

void	draw_vertical_line(t_cube *data, int x)
{
	double	wall_top;
	double	wall_bottom;

	wall_top = -data->var.line_height / 2 + SCREEN_HEIGHT / 2;
	wall_bottom = data->var.line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall_top < 0)
		wall_top = 0;
	if (wall_bottom >= SCREEN_HEIGHT)
		wall_bottom = SCREEN_HEIGHT - 1;
	draw_sky(data, wall_top, x);
	draw_walls(data, wall_top, wall_bottom, x);
	draw_flower(data, wall_bottom, x);
}
