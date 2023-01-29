/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:04:57 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 15:15:01 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_str(char *str, char const *buff)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	new = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			new[i] = str[i];
	while (buff[j] != '\0')
		new[i++] = buff[j++];
	new[i] = '\0';
	return (new);
}
