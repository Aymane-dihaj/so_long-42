/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:38:59 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 16:42:26 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_free(game->map);
	exit(0);
	return (0);
}

int	keyhook(int key, t_game *game)
{
	if (key == 53)
		ft_exit(game);
	if (key == 2 || key == 124)
		move_right(game);
	if (key == 0 || key == 123)
		move_left(game);
	if (key == 1 || key == 125)
		move_down(game);
	if (key == 13 || key == 126)
		move_up(game);
	return (0);
}
