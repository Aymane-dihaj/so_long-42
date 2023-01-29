/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:17:27 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 18:39:19 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(void *path, int y, int x, t_game game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
		path, y * 64, x * 64);
}

void	draw_player(t_game game, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_height(game.map))
	{
		j = -1;
		while (++j < map_width(game.map))
		{
			if (game.map[i][j] == 'P')
			{	
				put_img(game.floor, j, i, game);
				if (c == 'r')
					put_img(game.right, j, i, game);
				else if (c == 'l')
					put_img(game.left, j, i, game);
				else if (c == 'u')
					put_img(game.up, j, i, game);
				else if (c == 'd')
					put_img(game.down, j, i, game);
				else
					put_img(game.right, j, i, game);
			}
		}
	}
}

void	exit_animation(t_game game, int i, int j)
{
	find_exit(&game);
	if (count_elements(game.map, 'C') == 0)
	{
		mlx_destroy_image(game.mlx_ptr, game.img_ptr);
		put_img(game.floor, game.e_x, game.e_y, game);
		put_img(game.opened, game.e_x, game.e_y, game);
	}
	else
	{
		put_img(game.floor, game.e_x, game.e_y, game);
		put_img(game.closed, i, j, game);
	}
}

void	draw_stuff(t_game game, char c, int j, int i)
{
	if (c == 'C')
	{
		put_img(game.floor, j, i, game);
		put_img(game.money, j, i, game);
	}
}

void	draw_map(t_game game, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_height(game.map))
	{
		j = -1;
		while (++j < map_width(game.map))
		{
			if (game.map[i][j] == '1')
				put_img(game.wall, j, i, game);
			else if (game.map[i][j] == 'C')
				draw_stuff(game, 'C', j, i);
			else if (game.map[i][j] == '0')
				put_img(game.floor, j, i, game);
			else if (game.map[i][j] == 'E')
				exit_animation(game, j, i);
			else if (game.map[i][j] == 'P')
				draw_player(game, c);
		}
	}
}
