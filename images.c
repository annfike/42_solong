/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy <adelaloy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:39:30 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/04 14:42:19 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	file_to_image(t_data *data)
{
	int	i;
	int	j;

	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr, "img/floor1.xpm", &i,
			&j);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall1.xpm", &i,
			&j);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "img/cat1.xpm", &i,
			&j);
	data->img_to_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/mouse2_1.xpm", &i, &j);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit.xpm", &i,
			&j);
}

static void	choose_image(t_data *data, int y, int x)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_floor, x * SIZE, y * SIZE);
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_wall, x * SIZE, y * SIZE);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_player, x * SIZE, y * SIZE);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_to_collect, x * SIZE, y * SIZE);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit, x * SIZE, y * SIZE);
}

void	image_to_window(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			choose_image(data, y, x);
			x++;
		}
		y++;
	}
}
