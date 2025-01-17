/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:09:07 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 21:31:15 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*ft_strjoin(char *s1, char *s2, int free_s)
{
	char	*ptr;
	size_t	y;
	size_t	x;

	if (!s1 && !s2)
		return (ft_calloc(1, sizeof(char)));
	if (!s1 && s2)
		ptr = malloc((strln(s2) + 1) * sizeof(char));
	else if (s1 && !s2)
		ptr = malloc((strln(s1) + 1) * sizeof(char));
	else
		ptr = malloc((strln(s1) + strln(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	x = 0;
	y = 0;
	while (s1 && s1[x])
		ptr[y++] = s1[x++];
	x = 0;
	while (s2 && s2[x])
		ptr[y++] = s2[x++];
	ptr[y] = '\0';
	if (free_s == 1)
		ft_free(s1, s2);
	return (ptr);
}

char	*ft_strjoin_char(char *s1, char c)
{
	char	*ptr;
	size_t	y;
	size_t	x;

	if (!s1 && !c)
		return (ft_calloc(1, sizeof(char)));
	if (!s1 && c)
		ptr = malloc(2 * sizeof(char));
	else if (s1 && !c)
		ptr = malloc((strln(s1) + 1) * sizeof(char));
	else
		ptr = malloc((strln(s1) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	x = 0;
	y = 0;
	while (s1 && s1[x])
		ptr[y++] = s1[x++];
	x = 0;
	if (c)
		ptr[y++] = c;
	ptr[y] = '\0';
	return (ptr);
}
