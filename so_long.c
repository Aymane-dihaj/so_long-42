/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:20:24 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/28 20:20:31 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	you_win(t_game game, int y, int x)
{
	if ((game.collect == 0 && game.map[y][x - 1] == 'E') ||
		(game.collect == 0 && game.map[y][x + 1] == 'E') ||
		(game.collect == 0 && game.map[y - 1][x] == 'E') ||
		(game.collect == 0 && game.map[y + 1][x] == 'E'))
	{
		print_error("\033[0;32m\
		██╗░░░██╗░█████╗░██╗░░░██╗░██╗░░░░░░░██╗██╗███╗░░██╗\n\
		╚██╗░██╔╝██╔══██╗██║░░░██║░██║░░██╗░░██║██║████╗░██║\n\
		░╚████╔╝░██║░░██║██║░░░██║░╚██╗████╗██╔╝██║██╔██╗██║\n\
		░░╚██╔╝░░██║░░██║██║░░░██║░░████╔═████║░██║██║╚████║\n\
		░░░██║░░░╚█████╔╝╚██████╔╝░░╚██╔╝░╚██╔╝░██║██║░╚███║\n\
		░░░╚═╝░░░░╚════╝░░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
		ft_exit(&game);
	}
}

int	main(int ac, char **av)
{
	char	*map_path;
	t_game	game;

	if (ac == 2)
	{
		game.collect = 0;
		game.moves = 0;
		map_path = av[1];
		check_file(av[1]);
		get_map(av[1], &game);
		if (!game.map)
			print_error("\033[0;31mERROR:\ncan't open the map");
		map_checker(&game);
		mlx_loop(game.mlx_ptr);
	}
	else
		ft_putstr("\033[0;31mERROR:\nWrong number of arguments.");
	return (0);
}
