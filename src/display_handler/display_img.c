/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:19 by arocca            #+#    #+#             */
/*   Updated: 2025/03/10 12:33:42 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "so_long.h"

void	display_images(void *mlx, void *win, t_images img, t_map *map_data)
{
	int		x;
	int		y;
	void	*image;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			image = get_img(img, find_type(map_data->map[y][x]));
			if (image)
				mlx_put_image_to_window(mlx, win, image, x * SX, y * SY);
			x++;
		}
		y++;
	}
}

void	display_player(t_data *data, int *pos, t_images img, t_map *map_data)
{
	int	playerPosX = pos[0];
	int	playerPosY = pos[1];
	int	minX = playerPosX - (MAXW / 2);
	int maxX = playerPosX + (MAXW / 2);
	int	minY = playerPosY - (MAXH / 2);
	int maxY = playerPosY + (MAXH / 2);
	int i, j;
	void	*image;

	if (minY < 0)
	{
		maxY += -minY;
		minY = 0;
	}
	if (maxY > map_data->height)
	{
		minY -= maxY - map_data->height;
		maxY = map_data->height;
	}
	if (minX < 1)
	{
		maxX += -minX;
		minX = 0;
	}
	if (maxX > map_data->width - 1)
	{
		minX -= maxX - map_data->width;
		maxX = map_data->width;
	}
	j = 0;
	for (int y = minY; y < maxY; y++, j++)
	{
		i = 0;
		for (int x = minX; x < maxX; x++, i++)
		{
			image = get_img(img, find_type(map_data->map[y][x]));
			if (image)
				mlx_put_image_to_window(data->mlx, data->win, image, i * SX, j * SY);
		}
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

void	print_on_win(t_data *data, int *axis, int color, char *txt)
{
	mlx_string_put(data->mlx, data->win, axis[0] + 1, axis[1] + 1, BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0] + 1, axis[1] - 1, BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0] - 1, axis[1] + 1, BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0] - 1, axis[1] - 1, BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0], axis[1] - 1, BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0], axis[1] + 1, BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0] - 1, axis[1], BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0] + 1, axis[1], BLACK, txt);
	mlx_string_put(data->mlx, data->win, axis[0], axis[1], color, txt);
}