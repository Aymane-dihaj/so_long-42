NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC =	check_file.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		draw_map.c \
		find_player.c \
		ft_split.c \
		xpm_img.c \
		ft_itoa.c \
		map_check_helper.c \
		ft_strjoin.c \
		join_str.c \
		get_map.c \
		map_check2.c \
		keyhook.c \
		maps_checker.c \
		player_moves.c \
		so_long.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) so_long

re: fclean all