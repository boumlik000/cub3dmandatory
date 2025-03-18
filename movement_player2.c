/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_player2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:43:56 by mboumlik          #+#    #+#             */
/*   Updated: 2025/03/18 13:54:44 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update_player_position(t_cube *data, double old_x, double old_y)
{
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
		/ 64] == '0')
	{
		data->var.fn_map[(int)data->p_info.py / 64][(int)data->p_info.px
			/ 64] = data->var.char_of_player;
		data->var.fn_map[(int)old_y / 64][(int)old_x / 64] = '0';
	}
}

void	move_player_down_x(t_cube *data, double new_x, double new_y,
		double old_x)
{
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.px -= cos(data->p_info.pa * M_PI / 180.0) * SPEED;
	}
}

void	move_player_down_y(t_cube *data, double new_x, double new_y,
		double old_x)
{
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.py -= sin(data->p_info.pa * M_PI / 180.0) * SPEED;
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
	move_player_down_x(data, new_x, new_y, old_x);
	move_player_down_y(data, new_x, new_y, old_x);
	update_player_position(data, old_x, old_y);
}

void	move_player_left_x(t_cube *data, double new_x, double new_y,
		double old_x)
{
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.px += cos((data->p_info.pa - 90) * (M_PI / 180.0))
				* SPEED;
	}
}
