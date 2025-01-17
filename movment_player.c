/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:27:19 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 20:28:01 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_player_up(t_cube *data)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	new_x = data->p_info.px + cos(data->p_info.pa * (M_PI / 180.0)) * SPEED;
	new_y = data->p_info.py + sin(data->p_info.pa * M_PI / 180.0) * SPEED;
	old_x = data->p_info.px;
	old_y = data->p_info.py;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
		data->p_info.px += cos(data->p_info.pa * (M_PI / 180.0)) * SPEED;
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
		data->p_info.py += sin(data->p_info.pa * M_PI / 180.0) * SPEED;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
		/ 64] == '0')
	{
		data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
			/ 64] = data->var.char_of_player;
		data->var.fn_map[(int)old_y / 64][(int)old_x / 64] = '0';
	}
}

void	move_player_down(t_cube *data)
{
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	old_x = data->p_info.px;
	old_y = data->p_info.py;
	new_x = data->p_info.px - cos(data->p_info.pa * M_PI / 180.0) * SPEED;
	new_y = data->p_info.py - sin(data->p_info.pa * M_PI / 180.0) * SPEED;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
		data->p_info.px -= cos(data->p_info.pa * M_PI / 180.0) * SPEED;
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
		data->p_info.py -= sin(data->p_info.pa * M_PI / 180.0) * SPEED;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
		/ 64] == '0')
	{
		data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
			/ 64] = data->var.char_of_player;
		data->var.fn_map[(int)old_y / 64][(int)old_x / 64] = '0';
	}
}

void	move_player_left(t_cube *data)
{
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	old_x = data->p_info.px;
	old_y = data->p_info.py;
	new_x = data->p_info.px + cos((data->p_info.pa - 90) * (M_PI / 180.0))
		* SPEED;
	new_y = data->p_info.py + sin((data->p_info.pa - 90) * (M_PI / 180.0))
		* SPEED;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
		data->p_info.px += cos((data->p_info.pa - 90) * (M_PI / 180.0)) * SPEED;
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
		data->p_info.py += sin((data->p_info.pa - 90) * (M_PI / 180.0)) * SPEED;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
		/ 64] == '0')
	{
		data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
			/ 64] = data->var.char_of_player;
		data->var.fn_map[(int)old_y / 64][(int)old_x / 64] = '0';
	}
}

void	move_player_right(t_cube *data)
{
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	old_x = data->p_info.px;
	old_y = data->p_info.py;
	new_x = data->p_info.px + cos((data->p_info.pa + 90) * (M_PI / 180.0))
		* SPEED;
	new_y = data->p_info.py + sin((data->p_info.pa + 90) * (M_PI / 180.0))
		* SPEED;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
		data->p_info.px += cos((data->p_info.pa + 90) * (M_PI / 180.0)) * SPEED;
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
		data->p_info.py += sin((data->p_info.pa + 90) * (M_PI / 180.0)) * SPEED;
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
		/ 64] == '0')
	{
		data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
			/ 64] = data->var.char_of_player;
		data->var.fn_map[(int)old_y / 64][(int)old_x / 64] = '0';
	}
}
