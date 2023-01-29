/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:01:20 by adihaj            #+#    #+#             */
/*   Updated: 2022/12/22 18:33:15 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include "../so_long.h"
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(char *s);
char	*left_of_file(char *left_str);
char	*read_file(int fd, char *str);
char	*extract_line(char *str);
#endif