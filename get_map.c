/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:16:44 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 15:03:41 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(char *map_file, t_game *game)
{
	char	*line;
	char	*all;
	int		fd;

	line = "";
	all = ft_strdup("");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		print_error("\033[0;31mERROR:\nCan't open the file");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all = ft_strjoin(all, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all[0] == '\0' || all[0] == '\n' || all[ft_strlen(all) - 1] == '\n')
		print_error("\033[0;31mERROR:\nMap is NOT valid");
	game->map = ft_split(all, '\n');
	game->map_cp = ft_split(all, '\n');
	free(all);
}
