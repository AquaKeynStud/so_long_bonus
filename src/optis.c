/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:52:54 by arocca            #+#    #+#             */
/*   Updated: 2025/03/15 10:27:48 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (little[j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

bool	running_under_valgrind(void)
{
	int		fd;
	char	buffer[4096];
	ssize_t	bytes_read;

	fd = open("/proc/self/maps", O_RDONLY);
	if (fd < 0)
		return (false);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (ft_strstr(buffer, "valgrind"))
		{
			print_info_str("Program launched under valgrind", NULL);
			return (true);
		}
	}
	return (false);
}
