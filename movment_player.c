/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:27:19 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/03/18 13:58:34 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_player_left_y(t_cube *data, double new_x, double new_y,
		double old_x)
{
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.py += sin((data->p_info.pa - 90) * (M_PI / 180.0))
				* SPEED;
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
	move_player_left_x(data, new_x, new_y, old_x);
	move_player_left_y(data, new_x, new_y, old_x);
	update_player_position(data, old_x, old_y);
}

void	move_player_right_x(t_cube *data, double new_x, double new_y,
		double old_x)
{
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.px += cos((data->p_info.pa + 90) * (M_PI / 180.0))
				* SPEED;
	}
}

void	move_player_right_y(t_cube *data, double new_x, double new_y,
		double old_x)
{
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.py += sin((data->p_info.pa + 90) * (M_PI / 180.0))
				* SPEED;
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
	move_player_right_x(data, new_x, new_y, old_x);
	move_player_right_y(data, new_x, new_y, old_x);
	update_player_position(data, old_x, old_y);
}
