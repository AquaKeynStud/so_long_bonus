/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:44:59 by arocca            #+#    #+#             */
/*   Updated: 2025/03/03 12:48:35 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_queue	*queue_init(t_map *map, int start_x, int start_y)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->q = malloc(sizeof(t_case *) * (map->width * map->height));
	if (!q->q)
		return (free(q), NULL);
	q->front = 0;
	q->rear = 0;
	q->size = map->width * map->height;
	q->q[q->rear++] = &map->map[start_y][start_x];
	map->map[start_y][start_x].verified = true;
	return (q);
}

bool	has_unverified_neighbor(t_map *dmap, int x, int y)
{
	t_case	**map;
	int		height;
	int		width;

	map = dmap -> map;
	height = dmap -> height;
	width = dmap -> width;
	if (x + 1 < height && map[x + 1][y].type != '1' && !map[x + 1][y].verified)
		return (true);
	if (x - 1 >= 0 && map[x - 1][y].type != '1' && !map[x - 1][y].verified)
		return (true);
	if (y + 1 < width && map[x][y + 1].type != '1' && !map[x][y + 1].verified)
		return (true);
	if (y - 1 >= 0 && map[x][y - 1].type != '1' && !map[x][y - 1].verified)
		return (true);
	return (false);
}

void	handle_direction(t_map *map, t_queue *q, t_case *c, int direction)
{
	int	x;
	int	y;

	x = c->x;
	y = c->y;
	if (direction == 0)
		x--;
	else if (direction == 1)
		y++;
	else if (direction == 2)
		x++;
	else
		y--;
	if (x < 0 || y < 0 || x >= map -> height || y >= map -> width)
		return ;
	if (!map->map[x][y].verified && map->map[x][y].type != '1')
	{
		map->map[x][y].verified = true;
		if (q->rear < q->size && has_unverified_neighbor(map, x, y))
			q->q[q->rear++] = &map->map[x][y];
	}
}

void	bfs(t_map *map, int start_x, int start_y)
{
	t_queue	*queue;
	t_case	*cell;
	int		i;

	queue = queue_init(map, start_x, start_y);
	if (!queue)
		return ;
	while (queue->front != queue->rear)
	{
		cell = queue->q[queue->front++];
		i = 0;
		while (i < 4)
		{
			handle_direction(map, queue, cell, i);
			i++;
		}
	}
	free(queue->q);
	free(queue);
}

bool	is_item_unreachable(t_case cell)
{
	if (cell.verified == true || cell.type == '0')
		return (false);
	return (true);
}