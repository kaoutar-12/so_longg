/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:44:03 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/24 09:24:37 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <mlx.h>
# include "printf/ft_printf.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	t_data	*data;
	char	**new_map;
	char	**path_map;
	void	*c;
	void	*p;
	void	*w;
	void	*e;
	void	*f;
	char	*img;
	int		img_w;
	int		img_h;
	int		j;
	int		i;
	int		coli;
	int		ex;
	int		pl;
	int		count_move;
	int		p_x;
	int		p_y;
	size_t	first_line;
}	t_game;

int		check_name(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen( const char *s);
char	*get_next_line(int fd);
int		map_close(char **map);
char	**map_read(int fd, t_game *game);
char	*ft_strchr(const char *s, int c);
int		ft_playable(t_game *game);
int		map_size(t_game *game);
int		map_h(char **map);
void	xpm_to_img(t_game *game);
void	img_to_win(t_game *game);
void	ft_game(t_game *game);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
int		ft_close_game(t_game *game);
void	ft_find_player(t_game *game);
int		valid_path(t_game *game);
void	xpm_to_img(t_game *game);
void	img_to_win(t_game *game);
void	ft_find_player(t_game *game);
int		ft_key(int keycode, t_game *game);

#endif
