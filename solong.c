/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:39:14 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/11 15:21:53 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	count_lines(char **argv)
{
	int		fd;
	int		lines;
	char	*line;

	if (!check_file_format(argv[1]))
		show_error("Wrong format of file");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\n')
			show_error("First line is empty");
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}

int	check_map_width(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if (line[i - 1] == '\n')
		i--;
	return (i);
}

int	check_file_format(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == 'r' && s[i - 2] == 'e'
		&& s[i - 3] == 'b' && s[i - 4] == '.')
		return (1);
	return (0);
}

int	read_map(t_data *data, char **argv)
{
	char	*line;
	int		lines;
	int		fd;

	lines = count_lines(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	data->map = (char **)malloc(sizeof(char *) * (lines));
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map[lines] = line;
		lines++;
	}
	close(fd);
	if (lines == 0)
		return (0);
	data->map_height = lines;
	data->map_width = check_map_width(data->map[0]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	read_map(&data, argv);
	check_map(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * SIZE,
			data.map_height * SIZE, "solong");
	file_to_image(&data);
	image_to_window(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, close_game, &data);
	mlx_loop(data.mlx_ptr);
}

/* 
mlx_hook(void *win_ptr, int x_event, int x_mask, int (*func)(), void *param);
x_event=17=кнопка закрытия, x_mask=0=игнорируется в MacOS

make
./so_long maps/map.ber
leaks --atExit -- ./so_long map.ber
valgrind ./so_long map.ber
valgrind --leak-check=full --show-leak-kinds=all ./so_long map.ber
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes 
    --num-callers=20 --track-fds=yes ./so_long map.ber
 export MallocStackLogging=1 
 unset MallocStackLogging
 */
