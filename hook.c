/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:03:06 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 14:27:08 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	mouse_click(int button, int x, int y, t_cube *data)
{
	if ((x >= 591 && x <= 920) && (y >= 666 && y <= 942)
		&& data->var.start == 0)
	{
		data->var.music_flag = 0;
		data->var.start = 1;
		data->var.current_frame = 0;
	}
	else if ((x >= 591 && x <= 920) && (y >= 666 && y <= 942)
		&& data->var.start == 1)
	{
		data->var.music_flag = 0;
		data->var.start = 2;
	}
	(void)button;
	return (0);
}

int	key_press(int keycode, t_cube *data)
{
	if (keycode == 119 && data->var.start == 3)
		data->keys.key_up = 1;
	if (keycode == 115 && data->var.start == 3)
		data->keys.key_down = 1;
	if (keycode == 100 && data->var.start == 3)
		data->keys.key_right = 1;
	if (keycode == 97 && data->var.start == 3)
		data->keys.key_left = 1;
	if (keycode == 65361 && data->var.start == 3)
		turn_player_left(data);
	if (keycode == 65363 && data->var.start == 3)
		turn_player_right(data);
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 99 && data->var.start == 3 && data->var.camera_on == 0)
		data->var.camera_on = 1;
	else if (keycode == 99 && data->var.start == 3 && data->var.camera_on == 1)
		data->var.camera_on = 0;
	return (0);
}

int	mouse_move(int x, int y, t_cube *data)
{
	(void)data;
	(void)y;
	if (data->var.start == 3 && data->var.camera_on == 1)
	{
		if (x > data->var.x_old_mouse)
			turn_player_right(data);
		else if (x < data->var.x_old_mouse)
			turn_player_left(data);
		data->var.x_old_mouse = x;
	}
	return (0);
}

int	key_release(int keycode, t_cube *data)
{
	if (keycode == 119 && data->var.start == 3)
		data->keys.key_up = 0;
	if (keycode == 115 && data->var.start == 3)
		data->keys.key_down = 0;
	if (keycode == 100 && data->var.start == 3)
		data->keys.key_right = 0;
	if (keycode == 97 && data->var.start == 3)
		data->keys.key_left = 0;
	return (0);
}
