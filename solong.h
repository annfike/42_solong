/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:32:58 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/11 15:42:56 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

# define SIZE 40
# define KEYUP 126
# define KEYDOWN 125
# define KEYRIGHT 124
# define KEYLEFT 123
# define KEYEXIT 53

typedef struct s_data
{
	char	**map;
	int		map_height;
	int		map_width;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_to_collect;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		moves_count;
	int		c_count;
	int		exit_count;
	int		object_count;
	int		player_count;
	int		**objects;
	int		**map_arr;
}	t_data;

/* solong.c */
int		count_lines(char **argv);
int		check_map_width(char *line);
int		check_file_format(char *s);
int		read_map(t_data *data, char **argv);

/* images.c */
void	file_to_image(t_data *data);
void	image_to_window(t_data *data);

/* moves.c */
int		key_hook(int keycode, t_data *data);
void	move_player(t_data *data, int y, int x);
int		close_game(t_data *data);

/* map_check.c */
void	check_map_chars(t_data *data);
void	check_walls(t_data *data);
void	check_rectangular(t_data *data);
void	check_map(t_data *data);

/* map_check_path.c */
void	check_valid_path(t_data *data);

/* fill_arrs.c */
void	fill_map_arr(t_data *data);
void	fill_arr_objects(t_data *data);

/* free.c */
void	show_error(char *str);
void	free_map(t_data *data);
void	free_objects(t_data *data);
void	free_map_arr(t_data *data);

/* utils.c */
void	*ft_memset(void *b, int c, size_t length);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
