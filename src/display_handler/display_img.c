/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:19 by arocca            #+#    #+#             */
/*   Updated: 2025/03/12 16:15:16 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_images(void *mlx, void *win, t_images img, t_map *map)
{
	int		x;
	int		y;
	void	*image;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			image = get_img(img, find_type(map->map[y][x]));
			if (image)
				mlx_put_image_to_window(mlx, win, image, x * SX, y * SY);
			x++;
		}
		y++;
	}
}

void	init_bounds(t_map *map, int *pos, int *bound)
{
	bound[0] = pos[0] - (MAXW / 2);
	bound[1] = pos[0] + (MAXW / 2);
	bound[2] = pos[1] - (MAXH / 2);
	bound[3] = pos[1] + (MAXH / 2);
	if (bound[2] < 0)
	{
		bound[3] += -bound[2];
		bound[2] = 0;
	}
	if (bound[3] > map->height)
	{
		bound[2] -= bound[3] - map->height;
		bound[3] = map->height;
	}
	if (bound[0] < 1)
	{
		bound[1] += -bound[0];
		bound[0] = 0;
	}
	if (bound[1] > map->width - 1)
	{
		bound[0] -= bound[1] - map->width;
		bound[1] = map->width;
	}
}

void	display_player(t_data *data, int *pos, t_images imgs, t_map *map)
{
	int		x;
	int		y;
	int		bound[4];
	int		reset_x;
	void	*img;

	y = 0;
	init_bounds(map, pos, bound);
	reset_x = bound[0];
	while (bound[2] < bound[3])
	{
		x = 0;
		bound[0] = reset_x;
		while (bound[0] < bound[1])
		{
			img = get_img(imgs, find_type(map->map[bound[2]][bound[0]]));
			if (!img)
				return ;
			mlx_put_image_to_window(data->mlx, data->win, img, x * SX, y * SY);
			bound[0]++;
			x++;
		}
		bound[2]++;
		y++;
	}
}

void	update_images(t_data *data, t_case *aim, int x, int y)
{
	void		*mlx;
	void		*win;
	void		*img1;
	void		*img2;
	t_images	*img;

	mlx = data->mlx;
	win = data->win;
	img = data->images;
	img1 = get_img(*img, find_type((*data->map)->map[y][x]));
	img2 = get_img(*img, find_type((*data->map)->map[aim->y][aim->x]));
	mlx_put_image_to_window(mlx, win, img1, x * SX, y * SY);
	mlx_put_image_to_window(mlx, win, img2, aim->x * SX, aim->y * SY);
}

void	init_display(t_data data, t_map *map, t_images images)
{
	int	pos[2];

	get_axis(pos, data.pyx[1], data.pyx[0]);
	if (map->height > MAXH || map->width > MAXW)
		display_player(&data, pos, images, map);
	else
		display_images(data.mlx, data.win, images, map);
}
