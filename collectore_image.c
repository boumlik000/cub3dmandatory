/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectore_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:17:19 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 14:08:35 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_lstdelone_collec_img(t_colec *lst, t_cube *data)
{
	if (!lst)
		return ;
	mlx_destroy_image(data->mlx_init, lst->ptr);
	lst->ptr = NULL;
	free(lst);
	lst = NULL;
}

void	ft_lstclear_collec_img(t_colec **lst, t_cube *data)
{
	t_colec	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_collec_img(*lst, data);
		*lst = tmp;
	}
	*lst = NULL;
}
