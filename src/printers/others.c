/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:32:03 by arocca            #+#    #+#             */
/*   Updated: 2025/03/15 14:23:02 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_info_int(char *message, int v, int k)
{
	ft_printf("\033[34m\033[1m\033[107m%4cℹ️  Info : ", ' ');
	ft_printf(message, v, k);
	ft_printf("%4c\033[0m\n", ' ');
	return (ft_strlen(message));
}

int	print_info_str(char *message, char *value)
{
	ft_printf("\033[34m\033[1m\033[107m%4cℹ️  Info : ", ' ');
	ft_printf(message, value);
	ft_printf("%4c\033[0m\n", ' ');
	return (ft_strlen(message));
}

int	print_green(char *message)
{
	ft_printf("\033[32m\033[1m\033[107m%4c", ' ');
	ft_printf(message);
	ft_printf("%4c\033[0m\n", ' ');
	return (ft_strlen(message));
}

void	print_title(void)
{
	ft_printf("\033[36m\033[107m\033[1m");
	ft_printf("╒══════════════════════════════════════════════╕\n");
	ft_printf("%4c⛲ • Welcome to so_long • 🎍%4c\n", ' ', ' ');
	ft_printf("\033[0m\n");
}