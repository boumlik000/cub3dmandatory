/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trancp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:02:50 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 21:34:11 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_img	new_file_img(char *path, t_cube *data)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(data->mlx_init, path, &image.w,
			&image.h);
	ft_collectore(&data->list_img_head, image.img_ptr, "new_file_img");
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
				&(image.line_len), &(image.endian));
	return (image);
}

t_img	new_img(int w, int h, t_cube *data)
{
	t_img	image;

	image.img_ptr = mlx_new_image(data->mlx_init, w, h);
	ft_collectore(&data->list_img_head, image.img_ptr, "new_img");
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_len) + (x * img.bpp
				/ 8))));
}

void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			color = get_pixel_img(src, i, j);
			if (color != 0xFF000000)
			{
				put_pixel_img(dst, x + i, y + j, color);
			}
			j++;
		}
		i++;
	}
}
