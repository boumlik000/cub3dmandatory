/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:03:06 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 13:38:26 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_cube	data;

	if (argc == 2)
	{
		data.var.av = argv;
		inite(&data);
		ft_parse(&data);
		data.mlx_init = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_init, 1920, 1080, NAME);
		init_image(&data);
		mlx_mouse_hook(data.mlx_win, mouse_click, &data);
		mlx_loop_hook(data.mlx_init, display_frame, &data);
		mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
		mlx_hook(data.mlx_win, 6, 1L << 6, mouse_move, &data);
		mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
		mlx_hook(data.mlx_win, 17, 0, ft_exit, &data);
		mlx_loop(data.mlx_init);
	}
}
