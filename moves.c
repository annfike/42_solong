/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:41:07 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/11 15:08:06 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEYRIGHT || keycode == 65363 || keycode == 100
		|| keycode == 2)
		move_player(data, data->player_y, data->player_x + 1);
	else if (keycode == KEYLEFT || keycode == 65361 || keycode == 97
		|| keycode == 0)
		move_player(data, data->player_y, data->player_x - 1);
	else if (keycode == KEYUP || keycode == 65362 || keycode == 119
		|| keycode == 13)
		move_player(data, data->player_y - 1, data->player_x);
	else if (keycode == KEYDOWN || keycode == 65364 || keycode == 115
		|| keycode == 1)
		move_player(data, data->player_y + 1, data->player_x);
	else if (keycode == 53 || keycode == 65307)
		close_game(data);
	return (0);
}

static void	exit_game(t_data *data)
{
	ft_putstr_fd("You win!\n", 1);
	close_game(data);
	exit(0);
}

int	close_game(t_data *data)
{
	free_objects(data);
	free_map(data);
	free_map_arr(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	exit(0);
}

static void	print_moves(t_data *data)
{
	ft_putstr_fd("Total moves: ", 1);
	ft_putnbr_fd(data->moves_count, 1);
	ft_putstr_fd("\n", 1);
}

void	move_player(t_data *data, int y, int x)
{
	char	cell;

	cell = data->map[y][x];
	if (cell == 'E' && data->c_count == 0)
		exit_game(data);
	if (cell == '1' || cell == 'E')
		return ;
	if (cell == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[y][x] = 'P';
		image_to_window(data);
	}
	else if (cell == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[y][x] = 'P';
		data->c_count--;
		image_to_window(data);
	}
	data->player_y = y;
	data->player_x = x;
	data->moves_count++;
	print_moves(data);
}
