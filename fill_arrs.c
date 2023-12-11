/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:41:15 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/11 14:47:30 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fill_map_arr(t_data *data)
{
	int	i;

	i = 0;
	data->map_arr = (int **)malloc(sizeof(int *) * (data->map_height));
	while (i < data->map_height)
	{
		data->map_arr[i] = (int *)malloc(sizeof(int) * (data->map_width));
		ft_memset(data->map_arr[i], 0, sizeof(int) * data->map_width);
		i++;
	}
	data->map_arr[data->player_y][data->player_x] = 1;
}

static int	get_object_positions(t_data *data, int i, int j, int k)
{
	if (data->map[i][j] == 'P')
	{
		data->player_x = j;
		data->player_y = i;
	}
	if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
	{
		data->objects[k] = (int *)malloc(sizeof(int) * 2);
		data->objects[k][0] = i;
		data->objects[k][1] = j;
		k++;
	}
	return (k);
}

void	fill_arr_objects(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	data->object_count = data->c_count + 1;
	data->objects = (int **)malloc(sizeof(int *) * data->object_count);
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			k = get_object_positions(data, i, j, k);
			j++;
		}
		i++;
	}
}
