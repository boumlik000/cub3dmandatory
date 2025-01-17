/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:09:21 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/09/28 13:09:22 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*get_alls(int fd, char *buffer, t_cube *data, int x)
{
	char	*tmp;
	char	*text;

	text = malloc((size_t)BUFFER_SIZE + 1);
	if (text == NULL)
		return (NULL);
	while (!ft_strchr(buffer, '\n') || !ft_strchr(buffer, '\0'))
	{
		x = read(fd, text, BUFFER_SIZE);
		if (x <= 0)
			break ;
		text[x] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, text, 0);
		free(tmp);
	}
	free(text);
	if (x == 0)
		data->var.flag = 1;
	if (x < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_liness(char *buffer)
{
	char	*line;
	int		x;

	x = 0;
	while (buffer[x] && buffer[x] != '\n')
		x++;
	if (buffer[x] == '\n')
		x++;
	line = malloc(x + 1);
	if (line == NULL)
		return (NULL);
	x = 0;
	while (buffer[x] && buffer[x] != '\n')
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n')
	{
		line[x] = '\n';
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*add_next_line(char *buffer)
{
	int		x;
	char	*tmp;

	tmp = NULL;
	x = 0;
	while (buffer[x] && buffer[x] != '\n')
		x++;
	if (buffer[x] == '\0' || (buffer[x] == '\n' && buffer[x + 1] == '\0'))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	tmp = ft_strjoin(tmp, buffer + x + 1, 0);
	free(buffer);
	buffer = NULL;
	buffer = ft_strjoin(buffer, tmp, 0);
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd, t_cube *data)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = get_alls(fd, buffer, data, 1);
	if (buffer == NULL)
		return (NULL);
	line = get_liness(buffer);
	if (line == NULL)
		return (NULL);
	buffer = add_next_line(buffer);
	return (line);
}
