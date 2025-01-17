/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:44:34 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/17 11:59:01 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cheak_load_img(t_cube *data, char *img)
{
	if (cheak_name(data, img, ".xpm") == -1)
	{
		write(2, "Error In Game\n", 15);
		ft_exit(data);
	}
	data->var.check_img = mlx_xpm_file_to_image(data->mlx_init, img,
			&data->var.width, &data->var.height);
	if (data->var.check_img == NULL)
	{
		printf("error img =======> %s \n", img);
		write(2, "Error In Gamemlx\n", 18);
		perror("ss : ");
		ft_exit(data);
	}
	close(4);
	mlx_destroy_image(data->mlx_init, data->var.check_img);
}

void	init_image(t_cube *data)
{
	cheak_load_img(data, data->var.no);
	cheak_load_img(data, data->var.so);
	cheak_load_img(data, data->var.ea);
	cheak_load_img(data, data->var.we);
	data->var.img_no = new_file_img(data->var.no, data);
	data->var.img_so = new_file_img(data->var.so, data);
	data->var.img_ea = new_file_img(data->var.ea, data);
	data->var.img_we = new_file_img(data->var.we, data);
}

void	init_2(t_cube *data)
{
	data->keys.key_up = 0;
	data->keys.key_down = 0;
	data->keys.key_left = 0;
	data->keys.key_right = 0;
	data->list_img_head = NULL;
	data->var.music_flag = 0;
	data->d_rad = 0;
	data->d_ray_dir_x = 0;
	data->d_ray_dir_y = 0;
	data->d_map_x = 0;
	data->d_map_y = 0;
	data->d_delta_dist_x = 0;
	data->d_delta_dist_y = 0;
	data->d_step_x = 0;
	data->d_step_y = 0;
	data->d_side_dist_x = 0;
	data->d_side_dist_y = 0;
	data->d_hit = 0;
	data->d_side = 0;
	data->ray_angle = 0;
	data->perp_dist = 0;
	data->angle_diff = 0;
}

void	inite(t_cube *data)
{
	data->var.key_rels_up = 0;
	data->var.camera_on = 0;
	data->list_collecte_head = NULL;
	data->var.x = 0;
	data->var.y = 0;
	data->var.fd = 0;
	data->var.start = 2;
	data->var.flag = 0;
	data->var.map = NULL;
	data->var.current_frame = 0;
	data->var.last_time = 0;
	data->var.img_val = 6;
	data->var.img_serch = NULL;
	data->var.no = NULL;
	data->var.so = NULL;
	data->var.we = NULL;
	data->var.ea = NULL;
	data->var.num = 0;
	data->var.largline = 0;
	data->var.line = 0;
	init_2(data);
}
