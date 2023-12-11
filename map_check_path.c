/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy <adelaloy@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:40:52 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/04 14:40:53 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	check_cells_around(t_data *data, int i, int j, int k)
{
	if (i > 0 && data->map_arr[i - 1][j] == 0 && (data->map[i - 1][j] == '0'
		|| data->map[i - 1][j] == 'E' || data->map[i - 1][j] == 'C'))
		data->map_arr[i - 1][j] = k + 1;
	if (j > 0 && data->map_arr[i][j - 1] == 0 && (data->map[i][j - 1] == '0'
		|| data->map[i][j - 1] == 'E' || data->map[i][j - 1] == 'C'))
		data->map_arr[i][j - 1] = k + 1;
	if (i < data->map_height - 1 && data->map_arr[i + 1][j] == 0
		&& (data->map[i + 1][j] == '0' || data->map[i + 1][j] == 'E'
			|| data->map[i + 1][j] == 'C'))
		data->map_arr[i + 1][j] = k + 1;
	if (j < data->map_width - 1 && data->map_arr[i][j + 1] == 0
		&& (data->map[i][j + 1] == '0' || data->map[i][j + 1] == 'E'
			|| data->map[i][j + 1] == 'C'))
		data->map_arr[i][j + 1] = k + 1;
}

static void	make_step(t_data *data, int k)
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
			if (data->map_arr[i][j] == k)
				check_cells_around(data, i, j, k);
			j++;
		}
		i++;
	}
}

void	check_valid_path(t_data *data)
{
	int	i;
	int	j;
	int	object_count;
	int	k;

	fill_map_arr(data);
	i = 0;
	j = 0;
	object_count = data->c_count + 1;
	k = 0;
	while (object_count--)
	{
		i = data->objects[object_count][0];
		j = data->objects[object_count][1];
		while (data->map_arr[i][j] == 0)
		{
			k++;
			if (k > data->map_height * data->map_width)
			{
				free_map(data);
				show_error("The map is not valid:");
			}
			make_step(data, k);
		}
	}
}
