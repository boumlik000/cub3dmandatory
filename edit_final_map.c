/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_final_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:17:42 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 21:32:13 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	last_lines(t_cube *data)
{
	int	j;
	int	s;

	j = 0;
	s = 0;
	while (data->var.end_map[j])
		j++;
	j--;
	while (data->var.end_map[j])
	{
		s = 0;
		while (is_white_space(data->var.end_map[j][s]) == 1)
			s++;
		if (is_white_space(data->var.end_map[j][s]) == 0
			&& data->var.end_map[j][s] != '\0')
			break ;
		j--;
	}
	data->var.last_ln = j;
	return (j);
}

int	line_map(t_cube *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->var.end_map[x])
	{
		y = 0;
		while (is_white_space(data->var.end_map[x][y]) == 1)
			y++;
		if (is_white_space(data->var.end_map[x][y]) == 0
			&& data->var.end_map[x][y] != '\0')
			break ;
		x++;
	}
	data->var.f_ln = x;
	return (last_lines(data) - x);
}

void	edit_final_map(t_cube *data)
{
	int	y;
	int	x;

	x = 0;
	data->var.fn_map = malloc((line_map(data) + 2) * sizeof(char *));
	ft_collectore(&data->list_collecte_head, data->var.fn_map,
		"edit_final_map");
	while (data->var.f_ln <= data->var.last_ln)
	{
		data->var.fn_map[x] = malloc((strln(data->var.end_map[data->var.f_ln])
					+ 1) * sizeof(char));
		ft_collectore(&data->list_collecte_head, data->var.fn_map[x],
			"edit_final_map");
		y = 0;
		while (data->var.end_map[data->var.f_ln][y])
		{
			data->var.fn_map[x][y] = data->var.end_map[data->var.f_ln][y];
			y++;
		}
		data->var.fn_map[x][y] = '\0';
		data->var.f_ln++;
		x++;
	}
	data->var.fn_map[x] = NULL;
}
