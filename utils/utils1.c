/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <rlamtaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:09:30 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/01/15 21:31:15 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

size_t	strln(const char *s)
{
	size_t	count;

	count = 0;
	while (s && s[count])
		count++;
	return (count);
}

static size_t	ft_size(long n)
{
	size_t	sum;

	sum = 0;
	if (n <= 0)
	{
		sum++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		sum++;
	}
	return (sum);
}

static void	ft_sign(char *str, long *nb)
{
	str[0] = '-';
	*nb = *nb * -1;
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long int	nb;

	nb = n;
	size = ft_size(nb);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
		ft_sign(str, &nb);
	while (nb > 0)
	{
		str[size--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
