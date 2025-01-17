/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:55:04 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 23:01:59 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	findno(t_cube *data)
{
	while (is_white_space(data->var.map[data->var.y]) == 1)
		data->var.y++;
	if (data->var.map[data->var.y] == 'N' && data->var.map[data->var.y
			+ 1] == 'O' && (data->var.map[data->var.y + 2] == ' '
			|| data->var.map[data->var.y + 2] == '\t'))
	{
		data->var.y = data->var.y + 3;
		data->var.img_val--;
		while (data->var.map[data->var.y] == ' '
			|| data->var.map[data->var.y] == '\t')
			data->var.y++;
		if (data->var.map[data->var.y] == '\n')
			ft_exit_1(data, 1);
		while (is_white_space(data->var.map[data->var.y]) == 0)
		{
			data->var.no = ft_strjoin_char(data->var.no,
					data->var.map[data->var.y]);
			ft_collectore(&data->list_collecte_head, data->var.no, "NO");
			data->var.y++;
		}
	}
}

void	findso(t_cube *data)
{
	while (is_white_space(data->var.map[data->var.y]) == 1)
		data->var.y++;
	if (data->var.map[data->var.y] == 'S' && data->var.map[data->var.y
			+ 1] == 'O' && (data->var.map[data->var.y + 2] == ' '
			|| data->var.map[data->var.y + 2] == '\t'))
	{
		data->var.y = data->var.y + 3;
		data->var.img_val--;
		while (data->var.map[data->var.y] == ' '
			|| data->var.map[data->var.y] == '\t')
			data->var.y++;
		if (data->var.map[data->var.y] == '\n')
			ft_exit_1(data, 1);
		while (is_white_space(data->var.map[data->var.y]) == 0)
		{
			data->var.so = ft_strjoin_char(data->var.so,
					data->var.map[data->var.y]);
			ft_collectore(&data->list_collecte_head, data->var.so, "SO");
			data->var.y++;
		}
	}
}

void	findwe(t_cube *data)
{
	while (is_white_space(data->var.map[data->var.y]) == 1)
		data->var.y++;
	if (data->var.map[data->var.y] == 'W' && data->var.map[data->var.y
			+ 1] == 'E' && (data->var.map[data->var.y + 2] == ' '
			|| data->var.map[data->var.y + 2] == '\t'))
	{
		data->var.y = data->var.y + 3;
		data->var.img_val--;
		while (data->var.map[data->var.y] == ' '
			|| data->var.map[data->var.y] == '\t')
			data->var.y++;
		if (data->var.map[data->var.y] == '\n')
			ft_exit_1(data, 1);
		while (is_white_space(data->var.map[data->var.y]) == 0)
		{
			data->var.we = ft_strjoin_char(data->var.we,
					data->var.map[data->var.y]);
			ft_collectore(&data->list_collecte_head, data->var.we, "WE");
			data->var.y++;
		}
	}
}

void	findea(t_cube *data)
{
	while (is_white_space(data->var.map[data->var.y]) == 1)
		data->var.y++;
	if (data->var.map[data->var.y] == 'E' && data->var.map[data->var.y
			+ 1] == 'A' && (data->var.map[data->var.y + 2] == ' '
			|| data->var.map[data->var.y + 2] == '\t'))
	{
		data->var.y = data->var.y + 3;
		data->var.img_val--;
		while (data->var.map[data->var.y] == ' '
			|| data->var.map[data->var.y] == '\t')
			data->var.y++;
		if (data->var.map[data->var.y] == '\n')
			ft_exit_1(data, 1);
		while (is_white_space(data->var.map[data->var.y]) == 0)
		{
			data->var.ea = ft_strjoin_char(data->var.ea,
					data->var.map[data->var.y]);
			ft_collectore(&data->list_collecte_head, data->var.ea, "EA");
			data->var.y++;
		}
	}
}
