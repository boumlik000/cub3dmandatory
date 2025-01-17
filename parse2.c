/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:42:45 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 23:02:46 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	first_line(t_cube *data)
{
	int	j;

	j = 0;
	data->var.end_map[data->var.line] = malloc((data->var.largline + 2)
			* sizeof(char));
	ft_collectore(&data->list_collecte_head, data->var.end_map[data->var.line],
		"first_line");
	while (j < data->var.largline)
	{
		data->var.end_map[data->var.line][j] = ' ';
		j++;
	}
	data->var.end_map[data->var.line][j] = '\n';
	j++;
	data->var.end_map[data->var.line][j] = '\0';
	data->var.line++;
}

void	middl_line(t_cube *data, int j)
{
	while (data->var.map[data->var.y])
	{
		data->var.end_map[data->var.line] = malloc((data->var.largline + 2)
				* sizeof(char));
		ft_collectore(&data->list_collecte_head,
			data->var.end_map[data->var.line], "middl_line");
		j = 0;
		while (data->var.map[data->var.y] != '\n' && data->var.map[data->var.y])
		{
			data->var.end_map[data->var.line][j] = data->var.map[data->var.y];
			j++;
			data->var.y++;
		}
		while (j < data->var.largline)
		{
			data->var.end_map[data->var.line][j] = ' ';
			j++;
		}
		data->var.end_map[data->var.line][j] = '\n';
		j++;
		data->var.end_map[data->var.line][j] = '\0';
		data->var.line++;
		if (data->var.map[data->var.y] != '\0')
			data->var.y++;
	}
}

void	last_line(t_cube *data)
{
	int	j;

	j = 0;
	data->var.end_map[data->var.line] = malloc((data->var.largline + 2)
			* sizeof(char));
	ft_collectore(&data->list_collecte_head, data->var.end_map[data->var.line],
		"last");
	while (j < data->var.largline)
	{
		data->var.end_map[data->var.line][j] = ' ';
		j++;
	}
	data->var.end_map[data->var.line][j] = '\n';
	j++;
	data->var.end_map[data->var.line][j] = '\0';
	data->var.line++;
	data->var.end_map[data->var.line] = NULL;
}

void	cheak_wall(t_cube *data, int d, int s)
{
	while (data->var.end_map[s])
	{
		d = 0;
		while (data->var.end_map[s][d])
		{
			if (is_valid(data->var.end_map[s][d]) == 1)
			{
				if (d == 0 || is_white_space(data->var.end_map[s - 1][d]) == 1
					|| data->var.end_map[s - 1][d] == '\0')
					ft_exit_1(data, 2);
				if (is_white_space(data->var.end_map[s + 1][d]) == 1
					|| data->var.end_map[s + 1][d] == '\0')
					ft_exit_1(data, 2);
				if (is_white_space(data->var.end_map[s][d + 1]) == 1
					|| data->var.end_map[s][d + 1] == '\0')
					ft_exit_1(data, 2);
				if (is_white_space(data->var.end_map[s][d - 1]) == 1
					|| data->var.end_map[s][d - 1] == '\0')
					ft_exit_1(data, 2);
			}
			d++;
		}
		s++;
	}
}
