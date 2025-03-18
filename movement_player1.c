/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_player1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:42:11 by mboumlik          #+#    #+#             */
/*   Updated: 2025/03/18 13:55:06 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_wall(t_cube *data, int x, int y)
{
	if (data->var.fn_map[y][x] != '1')
		return (1);
	return (0);
}

int	check_move_condition(t_cube *data, double new_x, double new_y, double old_x)
{
	if (check_wall(data, new_x / 64, data->p_info.py / 64) == 1
		&& check_wall(data, old_x / 64, new_y / 64) == 1
		&& check_wall(data, new_x / 64, new_y / 64) == 0)
		return (0);
	return (1);
}

void	move_player_up_x(t_cube *data, double new_x, double new_y, double old_x)
{
	if (data->var.fn_map[(int)data->p_info.py / 64][(int)new_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.px += cos(data->p_info.pa * (M_PI / 180.0)) * SPEED;
	}
}

void	move_player_up_y(t_cube *data, double new_x, double new_y, double old_x)
{
	if (data->var.fn_map[(int)new_y / 64][(int)old_x / 64] != '1')
	{
		if (check_move_condition(data, new_x, new_y, old_x))
			data->p_info.py += sin(data->p_info.pa * M_PI / 180.0) * SPEED;
	}
}

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
	move_player_up_x(data, new_x, new_y, old_x);
	move_player_up_y(data, new_x, new_y, old_x);
	update_player_position(data, old_x, old_y);
}
