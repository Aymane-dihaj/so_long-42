/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:15:08 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/23 19:14:19 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./gnl/get_next_line.h"

# define ESC_KEY 53
# define D_KEY 2
# define S_KEY 1
# define A_KEY 0
# define W_KEY 13

typedef struct t_data{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		win_w;
	void	*closed;
	void	*opened;
	void	*money;
	void	*floor;
	void	*left;
	void	*right;
	void	*up;
	void	*down;
	void	*wall;
	int		win_h;
	char	**map;
	int		x;
	int		y;
	char	**map_cp;
	int		e_x;
	int		e_y;
	int		collect;
	int		moves;
	char	*dir;
}	t_game;

void	check_file(char *file);
int		ft_exit(t_game *game);
void	print_error(char *str);
char	**ft_split(char *s, char c);
void	find_exit(t_game *game);
void	put_img(void *path, int y, int x, t_game game);
char	*ft_itoa(int n);
size_t	ft_strlen(char const *str);
int		check_nl(char **map);
void	you_win(t_game game, int y, int x);
char	*ft_strdup(char *str);
void	xpm_to_img(t_game *game);
void	map_checker2(t_game game);
void	map_checker3(t_game game);
int		map_frame_check(char **map);
void	get_map(char *map_file, t_game *game);
void	ft_free(char **strs);
void	find_player(t_game *game);
int		map_width(char **map);
int		map_height(char **map);
int		check_map_char(char **map);
int		count_elements(char **map, char c);
int		check_exit_valid(char **map, t_game game);
int		check_nl(char **map);
void	draw_map(t_game game, char c);
void	map_checker(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	increment_moves(t_game *game);
char	*join_str(char *str, char const *buff);
int		flood_fill_collectable(t_game *map, int x, int y, int isfirst);
void	move_up(t_game *game);
int		keyhook(int key, t_game *game);
void	ft_putstr(char *str);

#endif