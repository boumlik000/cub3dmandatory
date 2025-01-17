/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:31:41 by mboumlik          #+#    #+#             */
/*   Updated: 2025/01/17 13:57:45 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	perform_dda(t_cube *data)
{
	while (data->d_hit == 0)
	{
		if (data->d_side_dist_x < data->d_side_dist_y)
		{
			data->d_side_dist_x += data->d_delta_dist_x;
			data->d_map_x += data->d_step_x;
			data->d_side = 0;
		}
		else
		{
			data->d_side_dist_y += data->d_delta_dist_y;
			data->d_map_y += data->d_step_y;
			data->d_side = 1;
		}
		if (data->d_map_x < 0 || data->d_map_y < 0
			|| data->d_map_x >= (int)strln(data->var.fn_map[0])
			|| data->d_map_y >= get_map_height(data->var.fn_map))
			data->d_hit = 1;
		else if (data->var.fn_map[data->d_map_y][data->d_map_x] == '1')
			data->d_hit = 1;
	}
}

// Main DDA function that uses all helper functions
double	draw_line_dda(t_cube *data, double x1, double y1, double angle)
{
	init_ray_values(data, x1, y1, angle);
	calculate_step_dist(data, x1);
	calculate_step_dist_y(data, y1);
	data->d_hit = 0;
	data->d_side = 0;
	perform_dda(data);
	calculate_perp_dist(data, x1, y1);
	data->side = data->d_side;
	data->ray_dir_x = data->d_ray_dir_x;
	data->ray_dir_y = data->d_ray_dir_y;
	return (fabs(data->perp_wall_dist * 64.0));
}

int	calculate_x(t_cube *data, t_img texture)
{
	double	wall_x;
	int		tex_x;

	if (data->side == 0)
		wall_x = data->p_info.py / 64.0 + data->perp_wall_dist
			* data->ray_dir_y;
	else
		wall_x = data->p_info.px / 64.0 + data->perp_wall_dist
			* data->ray_dir_x;
	wall_x = wall_x - (int)wall_x;
	if (wall_x < 0)
		wall_x += 1;
	tex_x = (int)(wall_x * texture.w);
	if ((data->side == 0 && data->ray_dir_x > 0) || (data->side == 1
			&& data->ray_dir_y < 0))
		tex_x = texture.w - tex_x - 1;
	return (tex_x);
}

void	draw_3d(t_cube *data, double fov, double half_fov, double center_angle)
{
	data->x = 0;
	while (data->x < SCREEN_WIDTH)
	{
		data->ray_angle = center_angle - half_fov + (data->x * fov
				/ SCREEN_WIDTH);
		while (data->ray_angle >= 360.0)
			data->ray_angle -= 360.0;
		while (data->ray_angle < 0.0)
			data->ray_angle += 360.0;
		data->perp_dist = draw_line_dda(data, data->p_info.px, data->p_info.py,
				data->ray_angle);
		data->angle_diff = data->ray_angle - center_angle;
		while (data->angle_diff >= 180.0)
			data->angle_diff -= 360.0;
		while (data->angle_diff < -180.0)
			data->angle_diff += 360.0;
		data->perp_dist *= cos(data->angle_diff * M_PI / 180.0);
		if (data->perp_dist < 0.1)
			data->perp_dist = 0.1;
		data->var.line_height = (int)(SCREEN_HEIGHT / data->perp_dist * 64.0);
		draw_vertical_line(data, data->x);
		data->x++;
	}
}

void	render_3d_walls(t_cube *data)
{
	double	center_angle;
	double	fov;
	double	half_fov;

	data->render_img.img = mlx_new_image(data->mlx_init, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	data->render_img.addr = mlx_get_data_addr(data->render_img.img,
			&data->render_img.bits_per_pixel, &data->render_img.line_length,
			&data->render_img.endian);
	center_angle = data->p_info.pa;
	fov = 60.0;
	half_fov = fov / 2.0;
	draw_3d(data, fov, half_fov, center_angle);
	mlx_put_image_to_window(data->mlx_init, data->mlx_win, data->render_img.img,
		0, 0);
	mlx_destroy_image(data->mlx_init, data->render_img.img);
}
