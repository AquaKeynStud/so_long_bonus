/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:12:44 by arocca            #+#    #+#             */
/*   Updated: 2025/03/09 12:13:44 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

/* -- Includes -- */
# include "so_long.h"
# include <errno.h>

/* -- Functions -- */
int		err(char *message);
int		err_errno(int errnum);
int		err_v(char *message, char *value);

void	print_map(t_map *map);
void	print_win(t_data *data, int pos[2], char *text, int	moves);

#endif