/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:41:15 by adelaloy          #+#    #+#             */
/*   Updated: 2023/12/11 15:19:39 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	show_error(char *str)
{
	perror(str);
	exit(0);
}

void	free_objects(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->object_count)
	{
		free(data->objects[i]);
		i++;
	}
	free(data->objects);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_map_arr(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map_arr[i]);
		i++;
	}
	free(data->map_arr);
}
