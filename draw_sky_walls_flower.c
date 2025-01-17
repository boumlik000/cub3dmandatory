/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_walls_flower.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:02:51 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 21:31:15 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

double	calculate_darkness(double distance)
{
	double	max_visible_distance;
	double	darkness;

	max_visible_distance = 300.0;
	darkness = distance / max_visible_distance;
	if (darkness > 1.0)
		darkness = 1.0;
	if (darkness < 0.0)
		darkness = 0.0;
	return (darkness);
}

void	upload_texture(t_cube *data, t_img *texture)
{
	if (data->side == 0)
	{
		if (data->ray_dir_x > 0)
			*texture = data->var.img_we;
		else
			*texture = data->var.img_ea;
	}
	else
	{
		if (data->ray_dir_y > 0)
			*texture = data->var.img_no;
		else
			*texture = data->var.img_so;
	}
}

void	draw_flower(t_cube *data, double wall_bottom, int x)
{
	int		y;
	double	distance;
	double	darkness;

	y = wall_bottom + 1;
	while (y < SCREEN_HEIGHT)
	{
		distance = (SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT)) * 64.0;
		darkness = calculate_darkness(distance);
		put_image_whit_dark(data, darkness, x, y);
		y++;
	}
}

void	draw_sky(t_cube *data, double wall_top, int x)
{
	int	y;

	y = 0;
	while (y < wall_top)
	{
		my_mlx_pixel_put2(&data->render_img, x, y,
			(data->var.f[0] << 16) | (data->var.f[1] << 8) | data->var.f[2]);
		y++;
	}
}

void	draw_walls(t_cube *data, double wall_top, double wall_bottom, int x)
{
	t_img	texture;
	double	step;
	double	tex_pos;

	upload_texture(data, &texture);
	data->var.tex_x = calculate_x(data, texture);
	step = 1.0 * texture.h / data->var.line_height;
	tex_pos = (wall_top - SCREEN_HEIGHT / 2 + data->var.line_height / 2) * step;
	data->var.in1 = wall_top;
	while (data->var.in1 <= wall_bottom)
	{
		data->var.tex_y = (int)tex_pos & (texture.h - 1);
		data->var.color = get_pixel_img(texture, data->var.tex_x,
				data->var.tex_y);
		data->var.darkness = calculate_darkness(data->perp_wall_dist * 64.0);
		data->var.r = ((data->var.color >> 16) & 0xFF) * (1.0
				- data->var.darkness);
		data->var.g = ((data->var.color >> 8) & 0xFF) * (1.0
				- data->var.darkness);
		data->var.b = (data->var.color & 0xFF) * (1.0 - data->var.darkness);
		data->var.color = data->var.r << 16 | data->var.g << 8 | data->var.b;
		my_mlx_pixel_put2(&data->render_img, x, data->var.in1, data->var.color);
		tex_pos += step;
		data->var.in1++;
	}
}
