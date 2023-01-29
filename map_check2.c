/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:39:36 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/27 13:13:43 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit_valid(char **map, t_game game)
{
	find_exit(&game);
	if (map[game.e_y][game.e_x + 1] == 'F' ||
		map[game.e_y][game.e_x - 1] == 'F' ||
		map[game.e_y + 1][game.e_x] == 'F' ||
		map[game.e_y - 1][game.e_x] == 'F')
		return (1);
	return (0);
}

int	check_player_valid(char **map, t_game game)
{
	find_player(&game);
	if (map[game.y][game.x + 1] == 'F' || map[game.y][game.x - 1] == 'F' ||
		map[game.y + 1][game.x] == 'F' || map[game.y - 1][game.x] == 'F')
		return (1);
	return (0);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	map_checker2(t_game game)
{
	find_player(&game);
	if (map_frame_check(game.map) == 0)
		print_error("\033[0;31mERROR:\nmap frame not valid");
	else if (count_elements(game.map, 'C') == 0)
		print_error("\033[0;31mERROR:\nneed collectibles in the map");
	else if (count_elements(game.map, 'E') != 1)
		print_error("\033[0;31mERROR:\nneed one exit");
	else if (flood_fill_collectable(&game, game.y, game.x, 1) == 0)
		print_error("\033[0;31mERROR:\ncollectible need to be reacheble");
	else if (check_exit_valid(game.map_cp, game) == 0)
		print_error("\033[0;31mERROR:\nExit must be available");
	else if (check_player_valid(game.map_cp, game) == 0)
		print_error("\033[0;31mERROR:\nplayer must be in empty space");
	ft_free(game.map_cp);
}
