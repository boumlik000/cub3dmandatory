/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:39:16 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/16 20:39:31 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	turn_player_left(t_cube *data)
{
	data->p_info.pa -= ROTATE;
}

void	turn_player_right(t_cube *data)
{
	data->p_info.pa += ROTATE;
}
