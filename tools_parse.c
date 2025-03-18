/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:43:18 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/03/18 13:01:38 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	cheak_name(t_cube *data, char *name, char *exten)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = strln(name) - 4;
	while (exten[y])
		if (exten[y++] != name[x++])
			return (1);
	data->var.fd = open(name, O_RDWR);
	if (data->var.fd == -1)
		return (1);
	return (0);
}

void	ft_exit_1(t_cube *data, int err)
{
	if (err == 1)
		write(2, "ERROR In Map Info...\n", 21);
	if (err == 2)
		write(2, "ERROR In MAP ...\n", 17);
	ft_lstclear_collec(&data->list_collecte_head);
	exit(2);
}

int	ft_exit(t_cube *data)
{
	ft_lstclear_collec_img(&data->list_img_head, data);
	ft_lstclear_collec(&data->list_collecte_head);
	mlx_clear_window(data->mlx_init, data->mlx_win);
	mlx_destroy_window(data->mlx_init, data->mlx_win);
	mlx_destroy_display(data->mlx_init);
	free(data->mlx_init);
	exit(2);
	return (1);
}

int	ft_larg_line(char *str, int x)
{
	int	y;
	int	larg;

	larg = 0;
	y = 0;
	while (str[x])
	{
		y++;
		if (str[x] == '\n')
		{
			if (y > larg)
				larg = y;
			y = 0;
		}
		x++;
	}
	return (larg);
}

int	is_valid(char c)
{
	if (c == '0' || c == 'E' || c == 'S' || c == 'N' || c == 'W')
		return (1);
	return (0);
}
