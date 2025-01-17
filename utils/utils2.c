/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:09:38 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 21:31:15 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	totale;
	char	*ptr;

	ptr = NULL;
	if (size > 0 && nitems > 0)
	{
		totale = nitems * size;
		if (totale / nitems != size)
			return (NULL);
		ptr = malloc(totale);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, totale);
	}
	else if (size == 0 || nitems == 0)
	{
		ptr = malloc(1);
		ptr[0] = 0;
		return ((void *)ptr);
	}
	return ((void *)ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = strln(s);
	if ((char)c == 0)
		return ((char *)(s + len));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

long	ft_atoi(const char *nptr)
{
	long		i;
	long		sum;

	sum = 0;
	i = 1;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			i = -i;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		sum = (sum * 10) + *nptr - 48;
		nptr++;
	}
	return (sum * i);
}
