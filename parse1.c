/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:38:14 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 21:53:24 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	creat_2d_map(t_cube *data)
{
	int	j;

	j = data->var.y;
	while (data->var.map[data->var.y])
	{
		if (data->var.map[data->var.y] == '\n')
			data->var.line++;
		data->var.y++;
	}
	data->var.end_map = malloc(((data->var.line + 4) * sizeof(char *)));
	ft_collectore(&data->list_collecte_head, data->var.end_map, "first_line");
	data->var.y = j;
	data->var.line = 0;
	first_line(data);
	middl_line(data, 0);
	last_line(data);
}

void	cheak_player(char *str, int x, t_cube *data)
{
	while (is_white_space(str[x]) == 1)
		x++;
	data->var.num_player = 0;
	while (str[x])
	{
		if (str[x] == 'E' || str[x] == 'S' || str[x] == 'N' || str[x] == 'W')
			data->var.num_player++;
		if (str[x] == 'N')
			data->p_info.pa = 270;
		if (str[x] == 'S')
			data->p_info.pa = 90;
		if (str[x] == 'E')
			data->p_info.pa = 0;
		if (str[x] == 'W')
			data->p_info.pa = 180;
		if (str[x] == 'N' || str[x] == 'W' || str[x] == 'E' || str[x] == 'S')
			data->var.char_of_player = str[x];
		if (!(str[x] == 'E' || str[x] == 'S' || str[x] == 'N' || str[x] == 'W'
				|| str[x] == '0' || str[x] == '1' || str[x] == ' '
				|| str[x] == '\t' || str[x] == '\n'))
			ft_exit_1(data, 1);
		x++;
	}
	if (data->var.num_player != 1)
		ft_exit_1(data, 2);
}

void	check_map_is_double(char *str, int x, t_cube *data)
{
	int	y;

	y = 0;
	while (str[y])
		y++;
	y--;
	while (is_white_space(str[y]) == 1)
		y--;
	while (is_white_space(str[x]) == 1)
		x++;
	while (x < y)
	{
		if (str[x] == '\n')
		{
			x++;
			while (str[x] == ' ' || str[x] == '\t')
				x++;
			if (str[x] == '\n')
				ft_exit_1(data, 2);
		}
		x++;
	}
}

void	map_check(t_cube *data)
{
	data->var.y = 0;
	findno(data);
	findso(data);
	findwe(data);
	findea(data);
	find_f(data);
	data->var.num = 0;
	find_c(data);
	if (data->var.img_val != 0)
		ft_exit_1(data, 1);
	while (data->var.map[data->var.y] == ' '
		|| data->var.map[data->var.y] == '\t')
		data->var.y++;
	check_map_is_double(data->var.map, data->var.y, data);
	cheak_player(data->var.map, data->var.y, data);
	data->var.largline = ft_larg_line(data->var.map, data->var.y);
	creat_2d_map(data);
	cheak_wall(data, 0, 0);
}

void	ft_parse(t_cube *data)
{
	if (cheak_name(data, data->var.av[1], ".cub") == 1)
	{
		write(2, "Error In NAME FILE\n", 19);
		close(data->var.fd);
		ft_exit_1(data, 0);
	}
	while (data->var.flag == 0)
		data->var.map = ft_strjoin(data->var.map, get_next_line(data->var.fd,
					data), 1);
	ft_collectore(&data->list_collecte_head, data->var.map, "ft_parse");
	close(data->var.fd);
	map_check(data);
	edit_final_map(data);
}
