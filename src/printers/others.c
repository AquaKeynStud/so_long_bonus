/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:32:03 by arocca            #+#    #+#             */
/*   Updated: 2025/03/12 16:47:47 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_info(char *message, char *value)
{
	ft_printf("\033[34m\033[1m\033[47m     ");
	ft_printf(message, value);
	ft_printf("     \033[0m\n");
	return (ft_strlen(message));
}
