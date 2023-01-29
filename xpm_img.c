/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:53:37 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 19:16:42 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_game *game)
{
	int	w;
	int	h;

	game->opened = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/opened_door.xpm", &w, &h);
	game->closed = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/closed_door.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/floor.xpm", &w, &h);
	game->up = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/pacman_up.xpm", &w, &h);
	game->right = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/pacman_right.xpm", &w, &h);
	game->down = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/pacman_down.xpm", &w, &h);
	game->money = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/Money.xpm", &w, &h);
	game->left = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/pacman_left.xpm", &w, &h);
	if (!game->opened || !game->closed || !game->wall
		|| !game->floor || !game->right || !game->down
		|| !game->money || !game->left || !game->up)
		print_error("\033[0;31mERROR:\nfile path not valid\033[0m");
}
