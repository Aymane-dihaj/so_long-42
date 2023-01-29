/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:57:35 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 17:16:49 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	size_t			str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = (str_len - start);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[len] = '\0';
	return (new);
}

static int	word_counter(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	word_size(char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free1(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**strs;
	int		j;

	i = 0;
	j = 0;
	strs = (char **)malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (j < word_counter(s, c))
	{
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(s, i, word_size(s, c, i));
		if (!strs[j])
		{
			ft_free1(strs, j);
			return (NULL);
		}
		i += word_size(s, c, i);
		j++;
	}
	strs[j] = 0;
	return (strs);
}
