/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 08:07:14 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/22 18:32:22 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	increment_moves(t_game *game)
{
	char	*nb;
	char	*text;
	int		w;
	int		h;

	game->moves++;
	nb = ft_itoa(game->moves);
	text = join_str("Moves: ", nb);
	ft_putstr("\033[0;35m");
	ft_putstr(text);
	ft_putstr("\n");
	game->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/wall.xpm", &w, &h);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 5, 10, 0xFFFFF, text);
	free(nb);
	free(text);
}

void	move_right(t_game *game)
{
	game->collect = count_elements(game->map, 'C');
	if (game->map[game->y][game->x + 1] == 'E' && game->collect == 0)
		you_win(*game, game->y, game->x);
	if (game->map[game->y][game->x + 1] == '0' ||
		game->map[game->y][game->x + 1] == 'C')
	{
		if (game->map[game->y][game->x + 1] == 'C')
			game->collect--;
		game->map[game->y][game->x + 1] = 'P';
		game->map[game->y][game->x] = '0';
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(*game, 'r');
		increment_moves(game);
		find_player(game);
	}
}

void	move_left(t_game *game)
{
	game->collect = count_elements(game->map, 'C');
	if (game->map[game->y][game->x - 1] == 'E' && game->collect == 0)
		you_win(*game, game->y, game->x);
	if (game->map[game->y][game->x - 1] == '0' ||
		game->map[game->y][game->x - 1] == 'C')
	{
		if (game->map[game->y][game->x - 1] == 'C')
			game->collect--;
		game->map[game->y][game->x - 1] = 'P';
		game->map[game->y][game->x] = '0';
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(*game, 'l');
		increment_moves(game);
		find_player(game);
	}
}

void	move_up(t_game *game)
{
	game->collect = count_elements(game->map, 'C');
	if (game->map[game->y - 1][game->x] == 'E' && game->collect == 0)
		you_win(*game, game->y, game->x);
	if (game->map[game->y - 1][game->x] == '0' ||
		game->map[game->y - 1][game->x] == 'C')
	{
		if (game->map[game->y - 1][game->x] == 'C')
			game->collect--;
		game->map[game->y - 1][game->x] = 'P';
		game->map[game->y][game->x] = '0';
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(*game, 'u');
		increment_moves(game);
		find_player(game);
	}
}

void	move_down(t_game *game)
{
	game->collect = count_elements(game->map, 'C');
	if (game->map[game->y + 1][game->x] == 'E' && game->collect == 0)
		you_win(*game, game->y, game->x);
	if (game->map[game->y + 1][game->x] == '0' ||
		game->map[game->y + 1][game->x] == 'C')
	{
		if (game->map[game->y + 1][game->x] == 'C')
			game->collect--;
		game->map[game->y + 1][game->x] = 'P';
		game->map[game->y][game->x] = '0';
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(*game, 'd');
		increment_moves(game);
		find_player(game);
	}
}
