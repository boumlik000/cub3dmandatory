/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:43:44 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 18:30:05 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	first_frame(t_cube *data)
{
	if (data->var.start == 2)
	{
		data->imgs_red.img = mlx_new_image(data->mlx_init, 64, 64);
		data->imgs_red.addr = mlx_get_data_addr(data->imgs_red.img,
				&data->imgs_red.bits_per_pixel, &data->imgs_red.line_length,
				&data->imgs_red.endian);
		data->imgs_blue.img = mlx_new_image(data->mlx_init, 64, 64);
		data->imgs_blue.addr = mlx_get_data_addr(data->imgs_blue.img,
				&data->imgs_blue.bits_per_pixel, &data->imgs_blue.line_length,
				&data->imgs_blue.endian);
		data->imgs_player.img = mlx_new_image(data->mlx_init, 1, 1);
		data->imgs_player.addr = mlx_get_data_addr(data->imgs_player.img,
				&data->imgs_player.bits_per_pixel,
				&data->imgs_player.line_length, &data->imgs_player.endian);
		draw_block(&data->imgs_blue, 0x00FF00);
		draw_player(&data->imgs_player, 0x00FF00);
		draw_block(&data->imgs_red, 0x00FF00);
		draw_map(data);
		data->var.x_old_mouse = data->p_info.px;
		ft_collectore(&data->list_img_head, data->imgs_red.img, "mouse_click");
		ft_collectore(&data->list_img_head, data->imgs_blue.img, "mouse_click");
		ft_collectore(&data->list_img_head, data->imgs_player.img,
			"mouse_click");
		data->var.start = 3;
	}
}

void	secend_frame(t_cube *data)
{
	if (data->var.start == 3)
	{
		render_3d_walls(data);
		if (data->keys.key_up)
			move_player_up(data);
		if (data->keys.key_down)
			move_player_down(data);
		if (data->keys.key_left)
			move_player_left(data);
		if (data->keys.key_right)
			move_player_right(data);
	}
}

int	display_frame(t_cube *data)
{
	first_frame(data);
	secend_frame(data);
	return (0);
}
