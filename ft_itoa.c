/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:36:15 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/22 18:15:43 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nbr_len(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	len = nbr_len(n);
	nbr = (long)n;
	str = (char *)(malloc(sizeof(char) * len + 1));
	if (str != NULL)
	{
		str[len--] = '\0';
		if (nbr < 0)
		{
			str[0] = '-';
			nbr = nbr * -1;
		}
		if (nbr == 0)
			str[0] = '0';
		while (nbr)
		{
			str[len--] = (nbr % 10) + 48;
			nbr = nbr / 10;
		}
	}
	return (str);
}
