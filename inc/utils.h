/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:38:27 by arocca            #+#    #+#             */
/*   Updated: 2025/03/16 12:39:22 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* -- Includes -- */
#include "so_long.h"

/* -- Utils -- */
char	*ft_itoa(int n);

int		type_of(t_case cell);
int		get_pos(t_map *map, char axis);
int		browse_map(t_map *map, bool (*function)(t_case cell));
int		*get_axis(int tab[2], int x, int y);

void	*get_img(t_data *data, t_images img, int y, int x);

/* -- Optimisations -- */
bool	running_under_valgrind(void);

#endif