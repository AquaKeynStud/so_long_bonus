/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:19 by arocca            #+#    #+#             */
/*   Updated: 2025/03/07 14:50:04 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "so_long.h"

void	display_images(void *mlx, void *win, t_images img, t_map *map_data)
{
	int		x;
	int		y;
	char	t;
	void	*image;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			t = find_type(map_data->map[y][x]);
			image = get_img(img, t);
			if (image)
				mlx_put_image_to_window(mlx, win, image, x * SX, y * SY);
			x++;
		}
		y++;
	}
}
