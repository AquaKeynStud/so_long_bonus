/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:12:44 by arocca            #+#    #+#             */
/*   Updated: 2025/03/06 16:25:46 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

/* -- Includes -- */
# include "map.h"
# include <errno.h>

/* -- Functions -- */
int		err(char *message);
int		err_errno(int errnum);
int		err_v(char *message, char *value);

void	print_map(t_map *map);

#endif