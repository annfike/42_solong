/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy <adelaloy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:41:01 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/04 14:41:02 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_rectangular(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (i < data->map_height)
	{
		len = check_map_width(data->map[i]);
		if (len != data->map_width)
		{
			free_map(data);
			perror("The map is not a recangular:");
			exit(0);
		}
		i++;
	}
}

void	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if ((i == 0 || i == data->map_height - 1)
				|| (j == 0 || j == data->map_width - 1))
			{
				if (data->map[i][j] != '1')
				{
					free_map(data);
					show_error("The map is not surrounded by walls:");
				}
			}
			j++;
		}
		i++;
	}
}

static void	check_cell_char(t_data *data, int i, int j)
{
	if (data->map[i][j] != '0' && data->map[i][j] != '1'
			&& data->map[i][j] != 'P' && data->map[i][j] != 'C'
				&& data->map[i][j] != 'E')
	{
		free_map(data);
		show_error("The map contains invalid characters:");
	}
	if (data->map[i][j] == 'P')
		data->player_count++;
	if (data->map[i][j] == 'C')
		data->c_count++;
	if (data->map[i][j] == 'E')
		data->exit_count++;
}

void	check_map_chars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			check_cell_char(data, i, j);
			j++;
		}
		i++;
	}
	if (data->player_count != 1 || data->exit_count != 1
		|| data->c_count == 0)
	{
		free_map(data);
		show_error("Map error:");
	}
}

void	check_map(t_data *data)
{
	check_rectangular(data);
	check_walls(data);
	check_map_chars(data);
	fill_arr_objects(data);
	check_valid_path(data);
}
