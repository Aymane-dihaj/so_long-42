/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:51:45 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 16:47:21 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_width(char **map)
{
	return (ft_strlen(map[0]));
}

int	count_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	graphic(t_game game)
{
	xpm_to_img(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, map_width(game.map) * 64,
			map_height(game.map) * 64, "so_long");
	if (game.win_ptr == NULL)
	{
		free(game.win_ptr);
		print_error("\033[0;31mERROR:\nerror in the programme");
	}
	draw_map(game, 'o');
	mlx_hook(game.win_ptr, 2, 0, keyhook, &game);
	mlx_string_put(game.mlx_ptr, game.win_ptr, 5, 10, 0xFFFFF, "Moves: 0");
	mlx_hook(game.win_ptr, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx_ptr);
}

void	map_checker(t_game *game)
{
	if (count_elements(game->map, 'P') != 1)
	{
		print_error("\033[0;31mERROR:\nneed one player");
	}
	else if (check_map_char(game->map) == 0)
		print_error("\033[0;31mERROR:\nundefined character in the map");
	else
	{
		map_checker2(*game);
		game->mlx_ptr = mlx_init();
		if (game->mlx_ptr == NULL)
			print_error("\033[0;31mERROR:\nERROR IN THE PROGRAM");
		find_player(game);
		graphic(*game);
	}
}
