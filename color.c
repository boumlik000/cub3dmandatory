/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:03:06 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 23:11:49 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_add_color(t_cube *data, int num, int fl, int index)
{
	if (fl == 1)
		data->var.f[index] = num;
	else
		data->var.c[index] = num;
}

void	cheak_num(t_cube *data, char *color)
{
	int	x;

	x = 0;
	while (color[data->var.num] && color[data->var.num] != ',')
	{
		if (!(color[data->var.num] >= '0' && color[data->var.num] <= '9'))
			ft_exit_1(data, 1);
		x++;
		data->var.num++;
	}
	if ((color[data->var.num] != ',' && color[data->var.num] != '\0') || x > 3)
		ft_exit_1(data, 1);
}

void	cheak_color(t_cube *data, char *color, int x, int fl)
{
	int	m;

	m = 0;
	while (color[data->var.num])
	{
		x = ft_atoi(&color[data->var.num]);
		if (x > 255 || x < 0)
			ft_exit_1(data, 1);
		ft_add_color(data, x, fl, m);
		cheak_num(data, color);
		m++;
		if (color[data->var.num] == '\0')
			break ;
		data->var.num++;
		if (!(color[data->var.num] >= '0' && color[data->var.num] <= '9'))
			ft_exit_1(data, 1);
	}
	if (m != 3)
		ft_exit_1(data, 1);
}

void	find_f(t_cube *data)
{
	while (is_white_space(data->var.map[data->var.y]) == 1)
		data->var.y++;
	if (data->var.map[data->var.y] == 'F' && (data->var.map[data->var.y
				+ 1] == ' ' || data->var.map[data->var.y + 1] == '\t'))
	{
		data->var.y = data->var.y + 2;
		data->var.img_val--;
		while (data->var.map[data->var.y] == ' '
			|| data->var.map[data->var.y] == '\t')
			data->var.y++;
		if (data->var.map[data->var.y] == '\n')
			ft_exit_1(data, 1);
		while (is_white_space(data->var.map[data->var.y]) == 0)
		{
			data->var.img_serch = ft_strjoin_char(data->var.img_serch,
					data->var.map[data->var.y]);
			ft_collectore(&data->list_collecte_head, data->var.img_serch, "F");
			data->var.y++;
		}
		cheak_color(data, data->var.img_serch, 0, 1);
		data->var.img_serch = NULL;
	}
}

void	find_c(t_cube *data)
{
	while (is_white_space(data->var.map[data->var.y]) == 1)
		data->var.y++;
	if (data->var.map[data->var.y] == 'C' && (data->var.map[data->var.y
				+ 1] == ' ' || data->var.map[data->var.y + 1] == '\t'))
	{
		data->var.y = data->var.y + 2;
		data->var.img_val--;
		while (data->var.map[data->var.y] == ' '
			|| data->var.map[data->var.y] == '\t')
			data->var.y++;
		if (data->var.map[data->var.y] == '\n')
			ft_exit_1(data, 1);
		while (is_white_space(data->var.map[data->var.y]) == 0)
		{
			data->var.img_serch = ft_strjoin_char(data->var.img_serch,
					data->var.map[data->var.y]);
			ft_collectore(&data->list_collecte_head, data->var.img_serch, "C");
			data->var.y++;
		}
		cheak_color(data, data->var.img_serch, 0, 2);
		data->var.img_serch = NULL;
	}
}
