/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:25:28 by fgonzale          #+#    #+#             */
/*   Updated: 2024/03/11 21:21:35 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void free_identifiers(t_data *data)
{
	if (data->c)
		free(data->c);
	if (data->ea)
		free(data->ea);
	if (data->f)
		free(data->f);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
}

void ft_exit_error(char *msg, int exit_code, t_data *data)
{
	printf("Error\n");
	printf(RED "%s\n" RESET, msg);
	if (data != NULL)
	{
		if (data->map_tab)
			free_strs(data->map_tab);
		if (data->map_grid)
			free_strs(data->map_grid);
		free_identifiers(data);
		if (data->mlx.mlx_win)
			mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
		if (data->mlx.mlx_ptr)
		{
			mlx_destroy_display(data->mlx.mlx_ptr);
			free(data->mlx.mlx_ptr);
		}
	}
	exit(exit_code);
}
