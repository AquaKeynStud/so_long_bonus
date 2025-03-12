/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:32:11 by arocca            #+#    #+#             */
/*   Updated: 2025/03/12 16:17:36 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_monster(t_case cell)
{
	return (cell.type == 'M');
}

bool	get_slimes(t_map *map)
{
	int	x;
	int	y;
	int	index;
	int	count;

	x = 0;
	y = 0;
	index = 0;
	count = browse_map(map, is_monster);
	map->slime = malloc(sizeof(t_case *) * count);
	if (!map->slime)
		return (false);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x].type == 'M')
				map->slime[index++] = &map->map[y][x];
			x++;
		}	
		y++;
	}
	map->slimes = index;
	return (true);
}

static bool	update_aim(t_data *data, t_case **cell, int x, int y)
{
	int	player_x;
	int	player_y;

	player_x = data->pyx[1];
	player_y = data->pyx[0];
	if (player_x < x && (*data->map)->map[y][x - 1].type != '1')
		x--;
	else if (player_x > x && (*data->map)->map[y][x + 1].type != '1')
		x++;
	if (player_y < y && (*data->map)->map[y - 1][x].type != '1')
		y--;
	else if (player_y > y && (*data->map)->map[y + 1][x].type != '1')
		y++;
	if (x <= 0 || y <= 0 || x >= (*data->map)->width || y >= (*data->map)->height)
		return (false);
	*cell = &(*data->map)->map[y][x];
	if ((*cell)->type != '0' && (*cell)->type != 'P')
		return (false);
	return (true);
}

int	move_enemies(t_data *data)
{
	int	i;
	t_case	*aim;
	t_map	*map;

	i = 0;
	map = *data->map;
	if (++data->frame_count < data->max_frames || !(*data->map)->slimes)
        return (1);
    data->frame_count = 0;
	while (i < map->slimes)
	{
		if (update_aim(data, &aim, map->slime[i]->x, map->slime[i]->y))
		{
			if (aim->type == 'P')
				return (end_loop(data));
			map->slime[i]->type = '0';
			aim->type = 'M';
			map->slime[i] = aim;
			init_display(*data, map, *data->images);
		}
		i++;
	}
	return (0);
}
