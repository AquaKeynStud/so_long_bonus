/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:10:11 by arocca            #+#    #+#             */
/*   Updated: 2025/03/15 11:11:04 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* -- Includes -- */
# include <stdlib.h>
# include <stdbool.h>

/* -- Structures -- */
typedef struct s_queue
{
	t_case	**q;
	int		front;
	int		rear;
	int		size;
}				t_queue;

/* -- Functions -- */
bool	get_slimes(t_map *map);
bool	is_item_unreachable(t_case cell);
void	bfs(t_map *map, int start_x, int start_y);
int		err_map_parsing(t_map *map, t_data *data, const char *file);

#endif