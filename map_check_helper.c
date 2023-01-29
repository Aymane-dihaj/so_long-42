/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:59:05 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/22 18:21:52 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_collectable(t_game *game, int x, int y, int isfirst)
{
	if (isfirst == 1)
	{
		x = 0;
		while (x < map_height(game->map_cp))
		{
			y = 0;
			while (y < map_width(game->map_cp))
			{
				if (game->map_cp[x][y] == 'C')
					return (0);
				y++;
			}
			x++;
		}
	}
	return (1);
}

int	flood_fill_collectable(t_game *game, int x, int y, int isfirst)
{
	if (game->map_cp[x][y + 1] == '0' || game->map_cp[x][y + 1] == 'C')
	{
		game->map_cp[x][y + 1] = 'F';
		flood_fill_collectable(game, x, y + 1, 0);
	}
	if (game->map_cp[x][y - 1] == '0' || game->map_cp[x][y - 1] == 'C')
	{
		game->map_cp[x][y - 1] = 'F';
		flood_fill_collectable(game, x, y - 1, 0);
	}
	if (game->map_cp[x + 1][y] == '0' || game->map_cp[x + 1][y] == 'C')
	{
		game->map_cp[x + 1][y] = 'F';
		flood_fill_collectable(game, x + 1, y, 0);
	}
	if (game->map_cp[x - 1][y] == '0' || game->map_cp[x - 1][y] == 'C')
	{
		game->map_cp[x - 1][y] = 'F';
		flood_fill_collectable(game, x - 1, y, 0);
	}
	if (!check_valid_collectable(game, x, y, isfirst))
		return (0);
	return (1);
}

int	map_frame_check(char **map)
{
	int	widht;
	int	height;
	int	i;

	i = 0;
	widht = map_width(map);
	height = map_height(map);
	while (i < widht)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][widht - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
