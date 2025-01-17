/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:03:06 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/17 14:01:21 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_data *imgs, int x, int y, int color)
{
	char	*dst;

	dst = imgs->addr + (y * imgs->line_length + x * (imgs->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_block(t_data *imgs, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			my_mlx_pixel_put(imgs, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *imgs, int color)
{
	my_mlx_pixel_put(imgs, 0, 0, color);
}

int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	draw_map(t_cube *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->var.fn_map[x])
	{
		y = 0;
		while (data->var.fn_map[x][y])
		{
			if (data->var.start == 2 && is_player_char(data->var.fn_map[x][y]))
			{
				data->p_info.px = (y * 64) + 32;
				data->p_info.py = (x * 64) + 32;
			}
			y++;
		}
		x++;
	}
}
